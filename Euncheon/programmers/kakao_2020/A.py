# 문자열 압축
# 푸는 데 걸린 시간: 50분
# 50분 중 대부분은 파이썬 문법 까먹고 타입에러 잡느라 생긴듯
def get_dividers(n):
    result = []
    for i in range(1, n):
        result.append(i)
    return result

def get_zipped_str(s: str, n: int):
    result = ""
    tmpstr = ""
    tmpnum = 1
    for i in range(0, len(s), n):
        if s[i:i+n] == tmpstr:
            tmpnum += 1
        else:
            if tmpstr != "":
                if tmpnum != 1: 
                    result = result + (str(tmpnum) + tmpstr)
                else:
                    result += tmpstr
            tmpnum = 1
            tmpstr = s[i:i+n]

    if tmpnum != 1:
        result += str(tmpnum) + tmpstr
    else:
        result += tmpstr
    return result
    
def solution(s):
    input_len = len(s)
    answer = input_len
    divider_list = get_dividers(input_len)
    
    for i in divider_list:
        answer = min(answer, len(get_zipped_str(s, i)))
    
    return answer

def main():
    print(solution("abcabcabcabcdededededede"))

if __name__ == "__main__":
	main()