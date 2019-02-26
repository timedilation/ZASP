# 쓰기 전에 필요한 것

-`pip3 install --upgrade google-cloud-language` : python3 사용하고 있어서 pip3로 해줘야함
- [링크](https://cloud.google.com/natural-language/docs/reference/libraries?hl=ko#client-libraries-install-python) :Natural Language API Client Libraries credential 다운.json 파일만들고 경로 export 해주기

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
