from math import gcd
from typing import List
class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        n = len(nums)
        mx = max(nums)
        MOD = 10**9 + 7

        dp = [[[-1] * (mx + 1) for _ in range(mx + 1)] for _ in range(n + 1)]

        def solve(idx, seq1, seq2) -> int:
            if idx == n:
                notEmpty = (seq1 != 0 and seq2 != 0)
                Equal = (seq1 == seq2)

                return 1 if notEmpty and Equal else 0

            if dp[idx][seq1][seq2] != -1:
                return dp[idx][seq1][seq2]
            
            skip = solve(idx + 1, seq1, seq2)
            take1 = solve(idx + 1, gcd(seq1, nums[idx]), seq2)
            take2 = solve(idx + 1, seq1, gcd(seq2, nums[idx]))

            dp[idx][seq1][seq2] = (skip + take1 + take2) % MOD

            return dp[idx][seq1][seq2]
        
        return solve(0, 0, 0)