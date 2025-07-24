class Solution(object):
    def removeElement(self, nums, val):
        ans = 0
        idx = 0
        for num in nums:
            if(num != val):
                ans += 1
                nums[idx] = num
                idx += 1               
        for i in range(ans, len(nums)):
            nums[i] = '_'
        return ans
        