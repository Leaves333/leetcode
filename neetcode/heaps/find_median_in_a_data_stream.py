import heapq

class MedianFinder:

    def __init__(self):
        self.nums = []        

    def addNum(self, num: int) -> None:
        heapq.heappush(self.nums, num)

    def findMedian(self) -> float:
        if len(self.nums) % 2 == 0:
            nums = heapq.nsmallest((len(self.nums) // 2) + 1, self.nums)
            return (nums[-1] + nums[-2]) / 2
        else:
            return heapq.nsmallest((len(self.nums) // 2) + 1, self.nums)[-1]
        
