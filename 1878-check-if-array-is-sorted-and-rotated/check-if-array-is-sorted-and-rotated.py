class Solution(object):
    def check(self, nums):
        limit, i = nums[0], 1
        while i < len(nums) and nums[i] >= nums[i - 1]:
            i += 1
        if i >= len(nums):
            return True
        i += 1
        while i < len(nums) and nums[i] >= nums[i - 1] and nums[i] <= limit:
            i += 1
        if nums[-1] > limit:
            return False
        if i >= len(nums):
            return True
        return False
        
        