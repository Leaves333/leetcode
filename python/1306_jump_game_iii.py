class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:

        reachable = set([start])
        
        def search(x):
            nonlocal reachable
            if x + arr[x] < len(arr) and x + arr[x] not in reachable:
                reachable.add(x + arr[x])
                search(x + arr[x])
            if x - arr[x] >= 0 and x - arr[x] not in reachable:
                reachable.add(x - arr[x])
                search(x - arr[x])

        search(start)
        for i in range(len(arr)):
            if arr[i] == 0 and i in reachable:
                return True
        return False
