from re import L
from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        valid_combs = []
        queens = []

        columns = set()
        pos_diag = set()
        neg_diag = set()

        def backtrack():

            # base case
            if len(queens) == n:
                valid_combs.append(queens.copy())
                return
            
            # attempt to place a queen
            i = len(queens) # there can always only be one queen per row
            for j in range(n):
                
                if j in columns:
                    continue
                if i + j in neg_diag or i - j in pos_diag:
                    continue

                queens.append((i, j))
                columns.add(j)
                neg_diag.add(i + j)
                pos_diag.add(i - j)

                backtrack()

                queens.pop()
                columns.remove(j)
                neg_diag.remove(i + j)
                pos_diag.remove(i - j)
        
        backtrack()

        # generate the answer in the right format
        ans = []
        for comb in valid_combs:
            strings = [['.' for _ in range(n)] for _ in range(n)]
            for queen in comb:
                strings[queen[0]][queen[1]] = 'Q'
            strings = [''.join(strings[i]) for i in range(n)]
            ans.append(strings)
        return ans
