import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low, high = 1, 1000000000
        while low < high:
            mid = low + (high - low) // 2
            time_needed = sum([math.ceil(x / mid) for x in piles])
            print(low, high, mid, time_needed)
            if time_needed <= h:
                high = mid
            else:
                low = mid + 1
        return low