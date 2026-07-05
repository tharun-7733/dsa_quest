from typing import Tuple
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        MOD = 10**9 + 7

        dp = [[(-2, -1)] * n for _ in range(n)]

        def dfs(i, j) -> tuple[int, int]:
            if i > n - 1 or j > n - 1:
                return [-1, 0]
            if board[i][j] == 'X':
                return [-1, 0]
            
            if i == n - 1 and j == n - 1:
                return [0, 1]
            
            if dp[i][j][0] != -2:
                return dp[i][j]
            
            down = dfs(i + 1, j)
            right = dfs(i, j + 1)
            downRight = dfs(i + 1, j + 1)

            best_so_far = max((down[0], right[0], downRight[0]))
            ways = 0

            if best_so_far == -1:
                dp[i][j] = (-1, 0)
                return dp[i][j]

            if down[0] == best_so_far:
                ways = (ways + down[1]) % MOD
            if right[0] == best_so_far:
                ways = (ways + right[1]) % MOD
            if downRight[0] == best_so_far:
                ways = (ways + downRight[1]) % MOD

            val = 0
            if board[i][j] != 'S' and board[i][j] != 'E':
                val = int(board[i][j])
            
            dp[i][j] = (best_so_far + val, ways)

            return dp[i][j]
        
        ans = dfs(0, 0)

        if(ans[0] == -1):
            return [0, 0]
        
        return [ans[0], ans[1]]