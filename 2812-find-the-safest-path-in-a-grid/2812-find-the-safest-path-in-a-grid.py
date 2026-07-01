class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque()

        if grid[0][0] == 1 or grid[n - 1][n - 1] == 1:
            return 0
        
        dist = [[sys.maxsize] * n for _ in range(n)]
        vis = [[False] * n for _ in range(n)]

        #  O(N^2)
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j))
                    dist[i][j] = 0
                    vis[i][j] = True
        
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        # BFS from thieves to all the cells
        while q:
            i, j = q.popleft()

            for dx, dy in directions:
                ni, nj = i + dx, j + dy

                if 0 <= ni < n and 0 <= nj < n and vis[ni][nj] == False:

                    q.append((ni, nj))
                    dist[ni][nj] = 1 + dist[i][j]
                    vis[ni][nj] = True
        
        low = 0
        high = max(max(row) for row in dist)
        ans = 0

        while low <= high:
                mid = low + (high - low) // 2

                # Function for Binary Search on Safe Factors
                def check(mid) -> bool:

                    if dist[0][0] < mid:
                        return False

                    q2 = deque()
                    q2.append((0, 0))
                    directions2 = [(0, 1), (0, -1), (1, 0), (-1, 0)]

                    vis2 = [[False] * n for _ in range(n)]

                    vis2[0][0] = True

                    while q2:
                        i, j = q2.popleft()

                        if i == n - 1 and j == n - 1:
                            return True

                        for dx, dy in directions2:
                            ni, nj = i + dx, j + dy

                            if (0 <= ni < n and 0 <= nj < n and not vis2[ni][nj] and dist[ni][nj] >= mid):
                                q2.append((ni, nj))
                                vis2[ni][nj] = True

                    return False

                if check(mid):
                    low = mid + 1
                    ans = mid
                else:
                    high = mid - 1
        
        return ans