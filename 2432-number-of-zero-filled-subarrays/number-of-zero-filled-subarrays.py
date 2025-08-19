class Solution(object):
    def zeroFilledSubarray(self, nums):
        i = 0; n = 0; ans = 0
        for i in nums:
            if(i != 0):
                ans += n * (n + 1) // 2
                n = 0
            else:
                n += 1
        return ans + (n * (n + 1) // 2)
        