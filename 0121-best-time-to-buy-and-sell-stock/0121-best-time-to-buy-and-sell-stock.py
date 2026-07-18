class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        dp = [0] * n
        buy = sys.maxsize

        for i in range(n):
            buy = min(buy, prices[i])

            dp[i] = max(dp[i - 1], prices[i] - buy)

        return dp[n - 1]