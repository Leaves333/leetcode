import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:        
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            first = heapq.heappop(stones)
            second = heapq.heappop(stones)
            if first == second:
                continue
            heapq.heappush(stones, -abs(first - second))

        if len(stones) == 0:
            return 0
        return -stones[0]
