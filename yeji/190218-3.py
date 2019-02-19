N=int(input())
for testcase in range(1,N+1):
    index,character=input().split()
    index=int(index)
    canbelist=[]
    for i in range(len(character)//2):
        for j in range(1,len(character)-i+1):
            item1=character[i:i+j]
            item2=character[i+j:]
            ##item3=character[i:i+j:-1]
            item4=character[i+j::-1]
            if item1 not in canbelist: canbelist.append(item1)
            if item2 not in canbelist: canbelist.append(item2)
            #print(item1,item2,item3,item4)
    canbelist.sort()
    print(canbelist)
    #print("#{0} {1} {2}".format(testcase,canbelist[index-1][0],len(canbelist[index-1])))
#시간초과 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
