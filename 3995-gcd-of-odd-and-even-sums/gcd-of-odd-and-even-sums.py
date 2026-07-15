import math

class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return math.gcd(n * (n + 1) , n ** 2)
        