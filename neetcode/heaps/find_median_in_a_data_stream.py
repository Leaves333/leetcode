import heapq

class MedianFinder:

    def __init__(self):
        self.maxHeap = [] # stores bottom half of nums
        self.minHeap = [] # stores top half of nums

    def addNum(self, num: int) -> None:
        
        if len(self.maxHeap) == 0:
            heapq.heappush(self.maxHeap, -num)
        elif num > -self.maxHeap[0]:
            heapq.heappush(self.minHeap, num)
        else:
            heapq.heappush(self.maxHeap, -num)

        if (len(self.maxHeap) > len(self.minHeap) + 1):
            top = heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, -top)
        elif (len(self.minHeap) > len(self.maxHeap) + 1):
            top = heapq.heappop(self.minHeap)
            heapq.heappush(self.maxHeap, -top)

    def findMedian(self) -> float:
        if (len(self.maxHeap) > len(self.minHeap)):
            return -self.maxHeap[0]
        elif (len(self.minHeap) > len(self.maxHeap)):
            return self.minHeap[0]
        else:
            return (-self.maxHeap[0] + self.minHeap[0]) / 2
        
