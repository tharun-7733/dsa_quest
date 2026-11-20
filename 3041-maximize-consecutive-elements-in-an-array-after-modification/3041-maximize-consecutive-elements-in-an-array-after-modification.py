class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        nums.sort()

        dp = {}
        ans = 0

        for x in nums:
            # what if we increment cur val:- check the longest streak that had when we increment the cur val
            dp[x + 1] = max(dp.get(x + 1, 0), dp.get(x, 0) + 1)

            # what if we not increment cur val:- check the longest streak that had when we don't increment the cur val
            dp[x] = max(dp.get(x, 0), dp.get(x - 1, 0) + 1)

            # compare in between cur val incremented and not incremented
            ans = max(ans, dp.get(x + 1, 0), dp.get(x, 0))

        return ans
