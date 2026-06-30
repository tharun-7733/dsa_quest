class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        dp = [[sys.maxsize] * (amount + 1) for _ in range(n)]

        for j in range(amount + 1):
            if j % coins[0] == 0:
                dp[0][j] = j // coins[0]

        for i in range(1, n):
            for j in range(amount + 1):

                skip = dp[i - 1][j]

                take = sys.maxsize

                if coins[i] <= j and dp[i][j - coins[i]] != sys.maxsize:
                    take = 1 + (dp[i][j - coins[i]])
                
                dp[i][j] = min(skip, take)
        
        ans = dp[n - 1][amount]

        return -1 if ans == sys.maxsize else ans