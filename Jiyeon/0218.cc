#include <iostream>
#include <string>
using namespace::std;

bool doesPatternMatches(string pattern, string value)
{
    int aNum = 0, bNum = 0;
    for(int i=0; i<pattern.length(); i++) {
        if(pattern[i] == 'a')
            aNum++;
        else
            bNum++;
    }
    if(aNum == 0 || bNum == 0) {
        int ptnNum = (aNum == 0) ? bNum : aNum;
        int ptnLen = value.length()/ptnNum;

        if(value.length()%ptnNum != 0)
            return false;
        
        string subptn = value.substr(0, ptnLen);
        for(int valueIdx = ptnLen; valueIdx < value.length(); valueIdx+=ptnLen) {
            if(value.compare(valueIdx, ptnLen, subptn) != 0)
                return false;
        }

        return true;
    }

    for(int aLen = 1; aLen <= (value.length()-bNum)/aNum; aLen++) {
        bool patternMatches = true;
        int valueIdx = 0;

        if((value.length() - aLen*aNum)%bNum != 0){
            continue;
        }

        int bLen = (value.length() - aLen*aNum)/bNum;
        string ptnAStr = "", ptnBStr = "";
        for(int ptnIdx = 0; ptnIdx < pattern.length(); ptnIdx++) {
            if(pattern[ptnIdx] == 'a'){
                if(ptnAStr.length() == 0)
                    ptnAStr = value.substr(valueIdx, aLen);
                else {
                    if(value.compare(valueIdx, aLen, ptnAStr) != 0) {
                        patternMatches = false;
                        break;
                    }
                }
                valueIdx += aLen;
            } else {
                if(ptnBStr.length() == 0)
                    ptnBStr = value.substr(valueIdx, bLen);
                else {
                    if(value.compare(valueIdx, bLen, ptnBStr) != 0) {
                        patternMatches = false;
                        break;
                    }
                }
                valueIdx += bLen;
            }
        }
        if(patternMatches)
            return true;
    }

    return false;
}

int main()
{
    string pattern, value;
    cin >> pattern >> value;
    if(doesPatternMatches(pattern, value))
        cout << "yeah" << endl;
    else
        cout << "nooo" << endl;
}
