class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        freqA = [0 for _ in range(len(A) + 1)]
        freqB = [0 for _ in range(len(B) + 1)]
        ans = []
        for i in range(len(A)):
            freqA[A[i]] += 1
            freqB[B[i]] += 1
            common = 0
            for i in range(len(A) + 1):
                common += min(freqA[i], freqB[i])
            ans.append(common)
        return ans
            