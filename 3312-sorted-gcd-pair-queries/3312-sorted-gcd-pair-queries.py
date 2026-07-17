from bisect import bisect_left
from typing import List

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        mx = max(nums)

        # Frequency of each value
        freq = [0] * (mx + 1)
        for x in nums:
            freq[x] += 1

        # cnt_div[g] = count of numbers divisible by g
        cnt_div = [0] * (mx + 1)
        for g in range(1, mx + 1):
            for multiple in range(g, mx + 1, g):
                cnt_div[g] += freq[multiple]

        # exact_pairs[g] = number of pairs whose gcd is exactly g
        exact_pairs = [0] * (mx + 1)

        for g in range(mx, 0, -1):
            c = cnt_div[g]
            exact_pairs[g] = c * (c - 1) // 2

            for multiple in range(2 * g, mx + 1, g):
                exact_pairs[g] -= exact_pairs[multiple]

        # Prefix sum of pair counts
        prefix = [0] * (mx + 1)
        for g in range(1, mx + 1):
            prefix[g] = prefix[g - 1] + exact_pairs[g]

        # Answer queries
        ans = []
        for q in queries:
            ans.append(bisect_left(prefix, q + 1))

        return ans