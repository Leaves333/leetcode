from collections import Counter
from typing import List
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:

        count = Counter(tasks)
        heap = [-x for x in count.values()]
        heapq.heapify(heap)

        time = 0
        queue = []

        while len(heap) > 0 or len(queue) > 0:
            while len(queue) > 0 and queue[0][1] <= time:
                heapq.heappush(heap, queue.pop(0)[0])

            if len(heap) > 0:
                x = heapq.heappop(heap)
            else:
                x, time = queue.pop(0)

            if x < -1:
                queue.append((x + 1, time + n + 1))
            time += 1

        return time
