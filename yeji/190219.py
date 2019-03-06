class Solution:
    def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
        for i in range(0,len(nums)):
            if target-nums[i]==nums[i]:
                if nums.count(nums[i])==2:
                    return [index for index, value in enumerate(nums) if value == nums[i]]
                else: continue
            elif target-nums[i] in nums:
                return [i,nums.index(target-nums[i])]
        return None
