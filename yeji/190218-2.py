N=int(input())
for testcase in range(1,N+1):
    Anum, Bnum=map(int,input().split())
    awords=[]
    result=0
    for a in range(Anum):
        awords.append(input())
    for b in range(Bnum):
        temp=input()
        for i in range(Anum):
            if temp in awords[i][:len(temp)]:
                result+=1
                break
    print("#{0} {1}".format(testcase,result))
