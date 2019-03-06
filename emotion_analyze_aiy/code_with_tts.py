import argparse
import time
import threading
import locale
import logging

import sys
import os
import random
import scipy.io.wavfile
sys.path.append('/home/pi/OpenVokaturi-3-0/api/')
# print(sys.path)
import Vokaturi


from aiy.board import Board, Led
from aiy.leds import (Leds, Pattern, PrivacyLed, RgbLeds, Color)
from aiy.voice.audio import AudioFormat, play_wav, record_file, Recorder

from aiy.assistant.my_grpc import AssistantServiceClientWithLed
from aiy.cloudspeech import CloudSpeechClient

# nlp 감정분석 라이브러리
from google.cloud import language
from google.cloud.language import enums
from google.cloud.language import types

# tts 라이브러리
from google.cloud import texttospeech


text = None
duration = 0.

def text_to_audio(client, text, filename):

    # Set the text input to be synthesized
    synthesis_input = texttospeech.types.SynthesisInput(text=text)

    # voice gender ("neutral")
    voice = texttospeech.types.VoiceSelectionParams(
        language_code='ko-KR',
        ssml_gender=texttospeech.enums.SsmlVoiceGender.NEUTRAL)

    # Select the type of audio file you want returned
    audio_config = texttospeech.types.AudioConfig(
        audio_encoding=texttospeech.enums.AudioEncoding.LINEAR16)

    # Perform the text-to-speech request on the text input with the selected
    # voice parameters and audio file type
    response = client.synthesize_speech(synthesis_input, voice, audio_config)

    # The response's audio_content is binary.
    with open(filename, 'wb') as out:
        # Write the response to the output file.
        out.write(response.audio_content)

    return filename


def listen_me():

    global text, duration

    parser = argparse.ArgumentParser()
    parser.add_argument('--filename', '-f', default='recording.wav')
    args = parser.parse_args()

    # 라이브러리 준비
    Vokaturi.load("/home/pi/lib/piZero.so")
    
    # 클라우드 스피치, 텍스트 자연어처리, tts 클라이언트 각각 초기화
    client = CloudSpeechClient()
    nlp_client = language.LanguageServiceClient()
    tts_client = texttospeech.TextToSpeechClient()

    pos_wavs =[]
    neut_wavs =[]
    neg_wavs =[]
    intro_wavs=[]

    pos_wavs.append(text_to_audio(tts_client, '진짜?', '0.wav'))
    pos_wavs.append(text_to_audio(tts_client, '대박', '1.wav'))
    pos_wavs.append(text_to_audio(tts_client, '우와', '2.wav'))
    pos_wavs.append(text_to_audio(tts_client, '하하', '3.wav'))

    neut_wavs.append(text_to_audio(tts_client, '응', '10.wav'))
    neut_wavs.append(text_to_audio(tts_client, '그렇구나', '11.wav'))
    neut_wavs.append(text_to_audio(tts_client, '그래서?', '12.wav'))
    neut_wavs.append(text_to_audio(tts_client, '응응', '13.wav'))

    neg_wavs.append(text_to_audio(tts_client, '저런', '4.wav'))
    neg_wavs.append(text_to_audio(tts_client, '힘내', '5.wav'))
    neg_wavs.append(text_to_audio(tts_client, '에휴', '6.wav'))

    intro_wavs.append(text_to_audio(tts_client, '들어줄게. 얘기해봐', 'intro0.wav'))
    intro_wavs.append(text_to_audio(tts_client, '무슨 일 이야?', 'intro1.wav'))
    play_wav(random.choice(intro_wavs))

    logging.basicConfig(level=logging.INFO)

    with Board() as board:


        while True:

            print('말해보자.')
            text = None
            duration = 0.
            emotion = None

            def wait():
                global text, duration
                start = time.monotonic()

                while text is None:

                    # 텍스트로 인식
                    text = client.recognize(language_code='ko-KR')
                    duration = time.monotonic() - start

            # 녹음하면서
            record_file(AudioFormat.CD, filename=args.filename, wait= wait, filetype='wav')

            print(text)
            print('Recorded: %.02f seconds' % duration)

            if text in ['들어줘서 고마워', '내 얘기 들어줘서 고마워', '어시스턴트', '잘가', '잘 가']:
                return 
            

            # 텍스트 감정 분석
            document = types.Document(content=text, type=enums.Document.Type.PLAIN_TEXT)
            sentiment = nlp_client.analyze_sentiment(document=document).document_sentiment

            print('텍스트 감정 분석*********************************')
            print('Text: {}'.format(text))
            print('Sentiment: {}, {}'.format(sentiment.score, sentiment.magnitude))

            ##################### 실험후 바꿔도 됨 ####################
            pos_standard = 0.6
            neg_standard = 0.1
            # magnitude_standard = 0.1

            # text sentiment analysis is enough
            if (sentiment.score < neg_standard 
                    or sentiment.score > pos_standard) :
               if sentiment.score < neg_standard:
                    emotion=False
                    print("@@@negative")
               else:
                    emotion=True
                    print("@@@positive")

            else:
                # 녹음 파일 감정 분석
                print('오디오 감정 분석*********************************')
                (sample_rate, samples) = scipy.io.wavfile.read(args.filename)
                # print ("   sample rate %.3f Hz" % sample_rate)

                # print ("Allocating Vokaturi sample array...")
                buffer_length = len(samples)
                print ("   %d samples, %d channels" % (buffer_length, samples.ndim))
                c_buffer = Vokaturi.SampleArrayC(buffer_length)
                if samples.ndim == 1:  # mono
                    c_buffer[:] = samples[:] / 32768.0
                else:  # stereo
                    c_buffer[:] = 0.5*(samples[:,0]+0.0+samples[:,1]) / 32768.0

                # print ("Creating VokaturiVoice...")
                voice = Vokaturi.Voice (sample_rate, buffer_length)

                # print ("Filling VokaturiVoice with samples...")
                voice.fill(buffer_length, c_buffer)

                # print ("Extracting emotions from VokaturiVoice...")
                quality = Vokaturi.Quality()
                emotionProbabilities = Vokaturi.EmotionProbabilities()
                voice.extract(quality, emotionProbabilities)

                if quality.valid:
                    # print ("Neutral: %.3f" % emotionProbabilities.neutrality)
                    # print ("Happy: %.3f" % emotionProbabilities.happiness)
                    # print ("Sad: %.3f" % emotionProbabilities.sadness)
                    # print ("Angry: %.3f" % emotionProbabilities.anger)
                    # print ("Fear: %.3f" % emotionProbabilities.fear)
                    # fear 는 무시하도록 하자.

                    wave_score = emotionProbabilities.happiness - (emotionProbabilities.sadness + emotionProbabilities.anger)


                    if wave_score > 0 and sentiment.score > 0.4:
                        print('@@@긍정')
                        emotion=True
                    elif wave_score < 0 and sentiment.score < 0.4:
                        print('@@@부정')
                        emotion=False

                    # text 스코어와 wave 스코어가 불일치 할때는 중립반응 (emotion = None)


            # 여기서 부터 반응.
            
            with Leds() as leds:
                if emotion is True:
                    play_wav(random.choice(pos_wavs))
                    leds.pattern = Pattern.blink(100)
                    color = (255,255,0)
                    leds.update(Leds.rgb_pattern(color))
                    time.sleep(1)
                    # play_wav('laugh.wav')
                elif emotion is False:     
                    play_wav(random.choice(neg_wavs))
                    leds.pattern = Pattern.breathe(1000)
                    color = (102,140,255)
                    leds.update(Leds.rgb_on(color))
                    time.sleep(1)
                    # play_wav('people-cheering.wav')

                # 중립 리액션
                else:
                    play_wav(random.choice(neut_wavs))
                    leds.pattern = Pattern.blink(5)
                    color = (230,0,115)
                    leds.update(Leds.rgb_on(color))
                    time.sleep(1)



def main():

    with Board() as board:
        assistant = AssistantServiceClientWithLed(board,'ko-KR', 100)
        while True:
            logging.info('Press button to start conversation...')
            board.button.wait_for_press()
            logging.info('Conversation started!')
            listen_flag = assistant.conversation()
            if listen_flag:
                # '내 얘기 들어 봐','내 얘기 좀 들어 줘','얘기 들어 봐','얘기 들어 줘','내 얘기 좀 들어 봐'
                print('내 얘기좀 들어봐 모드 진입 @@@@@@@@@@@@')
                listen_me()


if __name__ == '__main__':
    main()