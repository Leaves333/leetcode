from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        visited = [[False for _ in grid[i]] for i in range(len(grid))]
        
        def dfs(x: int, y: int):
            visited[x][y] = True

            changes = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dx, dy in changes:
                new_x = x + dx
                new_y = y + dy
                if new_x < 0 or new_x >= len(grid) or new_y < 0 or new_y >= len(grid[x]):
                    continue
                if grid[new_x][new_y] == "0" or visited[new_x][new_y]:
                    continue
                dfs(new_x, new_y)

        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if not visited[i][j] and grid[i][j] == "1":
                    dfs(i, j)
                    ans += 1
        return ans
