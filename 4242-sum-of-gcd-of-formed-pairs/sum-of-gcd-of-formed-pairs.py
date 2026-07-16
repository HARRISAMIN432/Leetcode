import math

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        prefG = []
        mx, i, j, ans = 0, 0, len(nums) - 1, 0
        for num in nums:
            mx = max(mx, num)
            prefG.append(math.gcd(num, mx))
        prefG.sort()
        while i < j:
            ans += math.gcd(prefG[i], prefG[j])
            i += 1
            j -= 1
        return ans

        