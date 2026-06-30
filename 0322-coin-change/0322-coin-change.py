class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
    
        target = amount

        dp = [[-1] * (target + 1) for _ in range(n)]

        def solve(idx, target) -> int:
            if target == 0:
                return 0
            
            if idx >= n:
                return sys.maxsize

            if dp[idx][target] != -1:
                return dp[idx][target]

            skip = 0 + solve(idx + 1, target)

            take = sys.maxsize

            if coins[idx] <= target:

                res = solve(idx, target - coins[idx])

                if res != sys.maxsize:
                    take = 1 + res
            
            dp[idx][target] = min(take, skip)

            return dp[idx][target]
        
        ans = solve(0, amount)

        return -1 if ans == sys.maxsize else ans
