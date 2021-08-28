# 괄호 변환
# 푸는 데 걸린 시간: 21분
# 파이썬 삼항연산자 적응이 안된다
def is_straight(u):
    stack = []
    for c in u:
        if c == '(':
            stack.append(c)
        else:
            if not stack:
                return False
            elif stack[-1] == '(':
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True

def reverse(u):
    result = ''
    for c in u:
        result += ')' if c == '(' else '('
    return result

def solution(p):
    answer = ''
    if p == '':
        return answer
    
    count = 0
    i = 0
    u = ''
    v = ''
    for c in p:
        i += 1
        count += 1 if c == '(' else -1
        if count == 0:
            u = p[:i]
            v = p[i:]
            break
    
    if is_straight(u):
        answer = u
        answer += solution(v)
    else:
        answer = '('
        answer += solution(v)
        answer += ')'
        u = u[1:len(u)-1]
        u = reverse(u)
        answer += u
    
    return answer