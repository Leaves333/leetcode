from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        ans = nums[0]
        curMax, curMin = 1, 1

        for n in nums:
            tmp = curMax * n
            curMax = max(n, curMax * n, curMin * n)
            curMin = min(n, tmp, curMin * n)
            ans = max(ans, curMax)

        return ans
        
