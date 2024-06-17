import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        heap = []
        for i in range(min(len(nums), k)):
            heapq.heappush(heap, nums[i])
        for i in range(k, len(nums)):
            heapq.heappushpop(heap, nums[i])

        return heap[0]