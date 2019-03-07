nums=[3,2,2,3]
val=3
i=-1
for j in range(0,len(nums)):
    if nums[j]==val: continue
    else:
        i+=1
        nums[i]=nums[j]

print(nums[:i+1])
####################
nums=[3,2,2,3]
i=0
n=len(nums)
while i<n:
    if nums[i]==val:
        nums[i],nums[n-1]=nums[n-1],nums[i]
        n-=1
    else:
        i+=1
print(nums)
print(nums[:n])
