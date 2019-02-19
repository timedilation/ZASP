N=int(input())
for testcase in range(1,N+1):
    A1,B1=map(int,input().split(' '))
    awords=[]
    result=0
    for a in range(A1):
        awords.append(input())
    for b in range(B1):
        temp=input()
        if temp in awords: result+=1
    print("#{0} {1}".format(testcase,result))
