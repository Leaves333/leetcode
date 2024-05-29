import math

class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        start = []
        end = []

        for i in range(1, int(math.sqrt(n)) + 1):
            if n % i == 0:
                if n // i == i:
                    start.append(i)
                else:
                    start.append(i)
                    end.insert(0, n // i)
        start.extend(end)

        if k > len(start):
            return -1
        return start[k - 1]