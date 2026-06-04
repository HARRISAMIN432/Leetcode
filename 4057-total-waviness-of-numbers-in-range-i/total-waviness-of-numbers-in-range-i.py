class Solution(object):
    def totalWaviness(self, num1, num2):
        ans = 0
        for i in range(num1, num2 + 1):
            ans += self.cw(i)
        return ans

    def cw(self, n):
        ans = 0
        s = str(n)
        for i in range(1, len(s) - 1):
            if (s[i + 1] < s[i] and s[i] > s[i - 1]) or (s[i + 1] > s[i] and s[i] < s[i - 1]):
                ans += 1
        return ans
        