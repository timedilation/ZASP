# 쓰기 전에 필요한 것

- `pip3 install --upgrade google-cloud-language` : python3 사용하고 있어서 pip3로 해줘야함
- [링크](https://cloud.google.com/natural-language/docs/reference/libraries?hl=ko#client-libraries-install-python) : Natural Language API Client Libraries credential 다운.
- json 파일만들고 경로 export 해주기
	-  `~/.profile` 에 `export GOOGLE_APPLICATION_CREDENTIALS="/home/pi/[파일이름].json"` 추가하면 돼요

- `pip3 install google-assistant-library`

 
- rasbian 환경 언어 한글로 되어있어야 할듯..아마..

- 지연님 예지님 [오픈 보카투리](https://wolfpaulus.com/embedded/emotion-lamp/) 받으셔야함니당..
링크에서 Building Vokaturi for the Raspberry Pi’s 32bit Linux 여기부터 해주시면 됩니다. 

```bash
# Compiling for the Raspberry Pi Zero W:
gcc -Wall ./OpenVokaturi.c -lm -O3 -fPIC -shared -mcpu=arm1176jzf-s -mfpu=vfp -o piZero.so
mv ./piZero.so ~/lib
rm -rf ~/OpenVokaturi-3-0/bin

```
- 컴파일은 파이 제로 버전으로 해주세요!


---

- 파일이 두개가 됐어요.
- `my_grpc.py` 는  src/aiy/assist/ 안에 새로 파일을 만들어 복붙 저장해주세용
- 구글 어시스턴트(버튼 누르고 얘기해야함)로 시작해서 *'내 얘기 들어 봐','내 얘기 좀 들어 줘','얘기 들어 봐','얘기 들어 줘','내 얘기 좀 들어 봐'* 로 듣기 모드 진입
- 듣기 모드에서 *'들어줘서 고마워', '내 얘기 들어줘서 고마워', '어시스턴트', '잘가', '잘 가'* 로 어시스턴트 모드 복귀. (어시스턴트는 버튼 누르고)

#  tts 까지 하려면
- code_with_tts.py 파일로 분리했어요.
- `pip3 install --upgrade google-cloud-texttospeech` 
- 이것만 하시면 됩니다. 근데 위에꺼만큼 오래걸려요ㅠㅠ
그래도 다른 합성 목소리 넣을 수 있으니 하시면 좋을 것 같아요.
모드 전환 할때 *'들어줄게 얘기해봐' , '무슨 일 이야?'* 중에 랜덤 재생해요.  
```python
    pos_wavs.append(text_to_audio(tts_client, '진짜?', '0.wav'))
    pos_wavs.append(text_to_audio(tts_client, '대박', '1.wav'))
    pos_wavs.append(text_to_audio(tts_client, '우와', '2.wav'))
    pos_wavs.append(text_to_audio(tts_client, '하하', '3.wav'))

    neg_wavs.append(text_to_audio(tts_client, '저런', '4.wav'))
    neg_wavs.append(text_to_audio(tts_client, '힘내', '5.wav'))
    neg_wavs.append(text_to_audio(tts_client, '에휴', '6.wav'))
```
- 긍부정 랜덤재생 목소리도 합성할수 있습니다. 혹시 녹음할 시간 부족하면 이걸로 걍 하는 것도 나쁘지않을거가타요


