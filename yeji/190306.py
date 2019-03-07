nums=[1,2,2]
i=0
while True:
    print(nums)
    print(len(nums))
    print('test1',i)
    if i<len(nums):
        if nums.count(nums[i])>=2:
            del nums[i]
            print('test2',i)
        else:
            i+=1
            print('test3',i)
    else: break

################Solution
        i=0
        for j in range(1,len(nums)):
            if nums[i]==nums[j]:
                j+=1
            else:
                nums[i+1]=nums[j]
                i+=1
        return len(nums[:i+1])
