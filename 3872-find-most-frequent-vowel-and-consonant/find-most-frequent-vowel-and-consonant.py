from collections import Counter

class Solution(object):
    def maxFreqSum(self, s):
        freq = Counter(s)
        even = max(freq['a'], freq['e'], freq['i'], freq['o'], freq['u'])
        freq['a'], freq['e'], freq['i'], freq['o'], freq['u'] = 0, 0, 0, 0, 0
        odd = max(freq.values())
        return even + odd
        