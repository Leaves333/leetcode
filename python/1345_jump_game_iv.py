import queue
import gc

class Solution:
    def minJumps(self, arr: List[int]) -> int:

        n = len(arr)
        graph = {}
        for i in range(n):
            if arr[i] in graph:
                graph[arr[i]].append(i)
            else:
                graph[arr[i]] = [i]
        
        dist = 0
        cur = [0]
        visited = [False for _ in range(n)]
        
        while True:

            for x in cur:
                visited[x] = True
            
            new_cur = set()
            for x in cur:
                if x == n - 1:
                    return dist
                for dest in graph[arr[x]]:
                    if not visited[dest]:
                        new_cur.add(dest)
                if x + 1 < n and not visited[x + 1]:
                    new_cur.add(x + 1)
                if x - 1 >= 0 and not visited[x - 1]:
                    new_cur.add(x - 1)
                graph[arr[x]].clear()
            
            cur = list(new_cur)
            dist += 1