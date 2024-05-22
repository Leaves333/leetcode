class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:

        m = len(matrix)
        n = len(matrix[0])
        
        visited = [[False for _ in range(n)] for _ in range(m)]
        size = [[int(x) for x in matrix[i]] for i in range(m)]

        def dfs(i, j):

            visited[i][j] = True
            
            i_in_bound = i + 1 < m
            j_in_bound = j + 1 < n

            children = []
            if i_in_bound:
                if not visited[i + 1][j]:
                    dfs(i + 1, j)
                children.append(size[i + 1][j])
            if j_in_bound:
                if not visited[i][j + 1]:
                    dfs(i, j + 1)
                children.append(size[i][j + 1])
            if i_in_bound and j_in_bound:
                if not visited[i + 1][j + 1]:
                    dfs(i + 1, j + 1)
                children.append(size[i + 1][j + 1])

            if matrix[i][j] == "0":
                size[i][j] = 0
            elif i < m - 1 and j < n - 1:
                size[i][j] = min(children) + 1

        dfs(0, 0)
        print(size)

        ans = 0
        for row in size:
            for x in row:
                ans = max(ans, x)
        return ans ** 2
