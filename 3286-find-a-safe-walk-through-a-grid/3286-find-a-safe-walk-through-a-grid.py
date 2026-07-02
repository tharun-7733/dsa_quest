from collections import defaultdict, deque
import math
class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        adjList = defaultdict(list)

        n, m = len(grid), len(grid[0])

        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        for i in range(n):
            for j in range(m):

                for dr, dc in directions:
                    ni, nj = i + dr, j + dc

                    if 0 <= ni < n and 0 <= nj < m:
                        adjList[(i, j)].append((ni, nj))
        
        
        dist = defaultdict(lambda: math.inf)

        q = deque()

        q.append((0, 0))
        dist[(0, 0)] = grid[0][0]

        while q:
            (i, j) = q.popleft()

            for u, v in adjList[(i, j)]:

                wt = grid[u][v]

                if(dist[(i, j)] + wt < dist[(u, v)]):
                    dist[(u, v)] = dist[(i,j)] + wt

                    if wt == 1:
                        q.append((u, v))
                    else:
                        q.appendleft((u, v))
        
        optimal_health = dist[(n - 1, m - 1)]

        return (health - optimal_health) >= 1