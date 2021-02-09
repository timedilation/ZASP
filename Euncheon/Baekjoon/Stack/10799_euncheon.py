# 몸풀기 스택 문제
# 분류가 스택이지만 스택을 쓰지는 않는다
# 복잡도: O(n)

parentheses = input()
stacked = 0
n = 0
result = 0
flag = False
for ch in parentheses:
    if ch == '(':
        stacked += 1
        if flag and stacked > 1:
            result += 1
        flag = True
    elif ch == ')':
        stacked -= 1
        if flag:
            result += stacked
            flag = False

print(result)
        