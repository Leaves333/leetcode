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
                top = heapq.heappop(heap)
                if top < -1:
                    queue.append((top + 1, time + n + 1))
                time += 1
            else:
                top = queue.pop(0)
                time = top[1]
                if top[0] < -1:
                    queue.append((top[0] + 1, time + n + 1))
                time += 1

        return time
