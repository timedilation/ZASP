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

# nlp 감정분석 라이브러리
from google.cloud import language
from google.cloud.language import enums
from google.cloud.language import types

from aiy.cloudspeech import CloudSpeechClient

text = None
duration = 0.

def main():

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
            

            # 텍스트 감정 분석
            document = types.Document(content=text, type=enums.Document.Type.PLAIN_TEXT)
            sentiment = nlp_client.analyze_sentiment(document=document).document_sentiment

            print('텍스트 감정 분석*********************************')
            print('Text: {}'.format(text))
            print('Sentiment: {}, {}'.format(sentiment.score, sentiment.magnitude))

            ##################### 나중에 몇번 실험해보자 ####################
            pos_standard = 0.6
            neg_standard = 0.2
            magnitude_standard = 0.3

            # text sentiment analysis is enough
            if (sentiment.magnitude > magnitude_standard and sentiment.score < neg_standard 
                    or sentiment.magnitude > magnitude_standard and sentiment.score > pos_standard) :
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
            # board.led.state = Led.ON
            with Leds() as leds:
                if emotion is True:
                    leds.pattern = Pattern.blink(50)
                    color = (255,255,0)
                    leds.update(Leds.rgb_pattern(color))
                    # audio.play_wav('laugh.wav')
                else:       
                    leds.pattern = Pattern.breathe(1000)
                    color = (102,140,255)
                    leds.update(Leds.rgb_on(color))
                    # audio.play_wav('people-cheering.wav')


            # print('Playing...')
            # play_wav(args.filename)
            # print('Done.')

if __name__ == '__main__':
    main()