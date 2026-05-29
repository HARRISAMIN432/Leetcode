class Solution(object):
    def minElement(self, nums):
        INF = float('inf')
        mini = INF
        for i in range(len(nums)):
            num = nums[i]
            nums[i] = 0
            while num:
                nums[i] += num % 10
                num //= 10
            mini = min(mini, nums[i])
        return mini
        
        