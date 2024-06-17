import heapq

class Solution(object):
    def kClosest(self, points, k):

        heap = []

        for i in range(min(len(points), k)):
            dist = abs(points[i][0] ** 2) + abs(points[i][1] ** 2)
            heapq.heappush(heap, (dist * -1, points[i]))
        for i in range(k, len(points)):
            dist = abs(points[i][0] ** 2) + abs(points[i][1] ** 2)
            heapq.heappushpop(heap, (dist * -1, points[i]))

        return [x[1] for x in heap]