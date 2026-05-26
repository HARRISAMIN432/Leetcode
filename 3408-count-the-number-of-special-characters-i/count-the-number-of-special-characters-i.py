class Solution(object):
    def numberOfSpecialChars(self, word):
        freqs = [0] * 26
        freql = [0] * 26
        for c in word:
            if ord(c) >= 65 and ord(c) < 97:
                freql[ord(c) - 65] += 1
            else:
                freqs[ord(c) - 97] += 1
        ans = 0
        for i in range(26):
            if freql[i] != 0 and freqs[i] != 0:
                ans += 1
        return ans
        