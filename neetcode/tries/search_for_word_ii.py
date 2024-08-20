from typing import List

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        
        foundWords: dict[str, bool] = dict()
        for word in words:
            foundWords[word] = False

        visited: set[tuple[int, int]] = set()
        cur: List[str] = []
        def dfs(x: int, y: int):
            
            if (x, y) in visited:
                return

            visited.add((x, y))
            cur.append(board[x][y])

            cur_word = "".join(cur)
            if cur_word in foundWords:
                foundWords[cur_word] = True
        
            steps = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dx, dy in steps:
                new_x = x + dx
                new_y = y + dy
                if new_x >= 0 and new_x < len(board) and new_y >= 0 and new_y < len(board[new_x]):
                    dfs(new_x, new_y)

            visited.remove((x, y))
            cur.pop()

        for x in range(len(board)):
            for y in range(len(board[x])):
                dfs(x, y)

        ans: List[str] = []
        for word in foundWords:
            if foundWords[word]:
                ans.append(word)
        return ans
