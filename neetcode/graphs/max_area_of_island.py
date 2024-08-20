from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        max_size = 0
        cur = 0

        visited = [[False for _ in range(len(grid[i]))] for i in range(len(grid))]
        
        def dfs(x: int, y: int):

            if visited[x][y] or grid[x][y] == 0:
                return

            nonlocal cur, max_size
            visited[x][y] = True
            cur += 1
            max_size = max(max_size, cur)

            adjacent = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dx, dy in adjacent:
                new_x = x + dx
                new_y = y + dy
                if new_x >= 0 and new_x < len(grid) and new_y >= 0 and new_y < len(grid[new_x]):
                    dfs(new_x, new_y)

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if not visited[i][j] and grid[i][j] == 1:
                    cur = 0
                    dfs(i, j)

        return max_size
