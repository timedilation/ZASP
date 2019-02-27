import argparse
import time
import threading
import locale
import logging

import sys
import os
import scipy.io.wavfile
sys.path.append('/home/pi/OpenVokaturi-3-0/api/')
# print(sys.path)
import Vokaturi

from aiy.board import Board, Led
from aiy.leds import (Leds, Pattern, PrivacyLed, RgbLeds, Color)
from aiy.voice.audio import AudioFormat, play_wav, record_file, Recorder

from aiy.assistant.my_grpc import AssistantServiceClientWithLed
from google.assistant.library.event import EventType

# nlp 감정분석 라이브러리
from google.cloud import language
from google.cloud.language import enums
from google.cloud.language import types

from aiy.cloudspeech import CloudSpeechClient

text = None
duration = 0.

def listen_me():

    global text, duration

    parser = argparse.ArgumentParser()
    parser.add_argument('--filename', '-f', default='recording.wav')
    args = parser.parse_args()

    # 라이브러리 준비
    Vokaturi.load("/home/pi/lib/piZero.so")
    
    # 클라우드 스피치랑 텍스트 자연어처리 클라이언트 각각 초기화
    client = CloudSpeechClient()
    nlp_client = language.LanguageServiceClient()

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

                    if wave_score > 0:
                        print('@@@긍정')
                        emotion=True
                    else:
                        print('@@@부정')
                        emotion=False

            # text 분석 모호하고 wave 분석 실패했을때 (주로 목소리 짧아서)
            if emotion is None:
                print('please say again')
                # 아님 중립적 반응 넣어도 됨.
                continue

            # 여기서 부터 반응.
            
            with Leds() as leds:
                if emotion is True:
                    # tts.say('I am glad to hear that.')
                    # tts.say('진짜? 대박.')
                    leds.pattern = Pattern.blink(100)
                    color = (255,255,0)
                    leds.update(Leds.rgb_pattern(color))
                    time.sleep(1)
                    # play_wav('laugh.wav')
                else:       
                    # tts.say('I am sorry to hear that.')
                    # tts.say('저런. 힘내.')
                    leds.pattern = Pattern.breathe(1000)
                    color = (102,140,255)
                    leds.update(Leds.rgb_on(color))
                    time.sleep(1)
                    # play_wav('people-cheering.wav')


def main():

    with Board() as board:
        assistant = AssistantServiceClientWithLed(board,'ko-KR', 80)
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