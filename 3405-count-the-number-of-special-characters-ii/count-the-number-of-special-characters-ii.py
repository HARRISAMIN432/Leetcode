class Solution(object):
    def numberOfSpecialChars(self, word):
        low = [-1] * 26
        cap = [-1] * 26
        for i in range(len(word)):
            c = word[i]
            if ord(c) >= 97:
                low[ord(c) - 97] = i
            elif cap[ord(c) - 65] == -1:
                cap[ord(c) - 65] = i
        ans = 0
        for i in range(26):
            if low[i] != -1 and cap[i] != -1 and low[i] < cap[i]:
                    ans += 1
        return ans
        