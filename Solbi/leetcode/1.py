class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(nums):
            if target-x in d:
                return [i, d[target-x]]
            d[x] = i
