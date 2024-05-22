class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:

        m = len(matrix)
        n = len(matrix[0])
        
        horizontal = [[int(x) for x in matrix[i]] for i in range(m)]
        vertical = [[int(x) for x in matrix[i]] for i in range(m)]

        for i in range(m):
            for j in range(n - 2, -1, -1):
                if matrix[i][j] != "0":
                    horizontal[i][j] = horizontal[i][j + 1] + 1

        for j in range(n):
            for i in range(m - 2, -1, -1):
                if matrix[i][j] != "0":
                    vertical[i][j] = vertical[i + 1][j] + 1

        print(vertical)
        print(horizontal)

        longest_streak = 0
        for offset in range(-1 * (n - 1), m):

            cur_streak = 0
            for i in range(m):

                j = i - offset
                if i < 0 or j < 0 or i >= m or j >= n or matrix[i][j] == "0":
                    continue

                if cur_streak == 0:
                    cur_streak += 1
                elif vertical[i][j] < vertical[i - 1][j - 1] and horizontal[i][j] < horizontal[i - 1][j - 1]:
                    cur_streak += 1
                else:
                    cur_streak = 0
                
                longest_streak = max(cur_streak, longest_streak)
                print(i, j, cur_streak)
        
        return longest_streak ** 2