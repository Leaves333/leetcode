from typing import List

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        inc = [0 for _ in nums]
        dec = [0 for _ in nums]

        for q in queries:
            inc[q[0]] += 1
            dec[q[1]] += 1

        thresh = 0
        for i in range(len(nums)):
            thresh += inc[i]
            if nums[i] > thresh:
                return False
            thresh -= dec[i]
        return True
