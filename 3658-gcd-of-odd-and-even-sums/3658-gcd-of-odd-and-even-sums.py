import math
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return gcd((pow(n, 2)), (n * (n + 1)))