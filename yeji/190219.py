nums=list(map(int,input().split()))
target=int(input())
canbelist=[]
for i in range(1,target//2+1):
        item=[i,target-i]
        if i==target-i and nums.count(i) == 2:
            print( [index for index, value in enumerate(nums) if value == i] )
        elif item[0] in nums and item[1] in nums:
            print( [nums.index(item[0]),nums.index(item[1])] )
        #else: return None
