class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)

        dp = [[-1] * n for _ in range(n)]

        def solve(i: int, j: int) -> int:
            if i == j: return piles[i]
            
            if dp[i][j] != -1:
                return dp[i][j]

            take = solve(i + 1, j)
            skip = solve(i, j - 1)

            dp[i][j] = max(
                piles[i] - take,
                piles[j] - skip
            )

            return dp[i][j]

        solve(0, n - 1)
        return n - dp[n // 2][n // 2] >= 0