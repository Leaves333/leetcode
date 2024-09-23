from typing import List

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:

        map = {}
        for row in grid:
            if str(row) not in map:
                map[str(row)] = 0
            map[str(row)] += 1

        ans = 0
        for i in range(len(grid)):
            cur = []
            for j in range(len(grid)):
                cur.append(grid[j][i])
            if str(cur) in map:
                ans += map[str(cur)]

        return ans
