from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        visited = set()
        cur = []
        found = False

        def dfs(x: int, y: int):

            nonlocal found
            if (x, y) in visited or found:
                return

            visited.add((x, y))
            cur.append(board[x][y])

            if "".join(cur) == word:
                found = True
                return

            STEPS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dx, dy in STEPS:
                a, b = x + dx, y + dy
                if a >= 0 and a < len(board) and b >= 0 and b < len(board[a]):
                    dfs(a, b)

            visited.remove((x, y))
            cur.pop()

        for x in range(len(board)):
            for y in range(len(board[x])):
                visited.clear()
                cur.clear()
                dfs(x, y)
                if found:
                    return True

        return False
        
