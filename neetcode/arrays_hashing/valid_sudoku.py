class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
        for row in board:
            reduced = [x for x in row if x != '.']
            if len(set(reduced)) != len(reduced):
                return False
        
        for i in range(9):
            column = [board[j][i] for j in range(9) if board[j][i] != '.']
            if len(set(column)) != len(column):
                return False
            
        for i in range(3):
            for j in range(3):
                square = []
                for x in range(-1, 2):
                    for y in range(-1, 2):
                        cur = board[i * 3 + 1 + x][j * 3 + 1 + y]
                        if cur != '.':
                            square.append(cur)
                if len(set(square)) != len(square):
                    return False

        return True