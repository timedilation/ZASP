print("hello ")
#문제 설명
#리스트가 주어졌을 때
#동일 요소가 포함되지 않은 연속된 수열의 개수

#단순하게 생각하면 그냥 새로운 원소 나올 때마다 set에 추가하고 비교...?
inp = list(map(int,input().split()))
sum = 0
print('input',inp)
all = []
for i in range(len(inp)):
    temp = set([inp[i]])
    sum +=1
    all.append(temp)
    print('one',all)
    #print('current', temp,sum)
    j = i
    while (j != len(inp) -1 ):
        j +=1
        #print('j',j)
        if inp[j] not in temp:
            temp.add(inp[j])
            all.append(temp)
            print('add',all)
            sum += 1
            #print('add',temp,sum)
        else:
            #sum +=1
            #all.append(temp)
            #print(all)
            #print(sum,temp, i, j)
            break
    print(sum)
    print(all)
