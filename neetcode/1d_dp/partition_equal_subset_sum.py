from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        total_sum = sum(nums)
        if sum(nums) % 2 != 0:
            return False

        dp = {}
        def helper(n, target_sum) -> bool:

            # base case
            if target_sum == 0:
                return True
            elif n == 0:
                return False

            if n in dp and target_sum in dp[n]:
                return dp[n][target_sum]

            first = helper(n - 1, target_sum) 
            second = helper(n - 1, target_sum - nums[n - 1])

            if n not in dp:
                dp[n] = {}
            dp[n][target_sum] = first or second
            return first or second
            
        return helper(len(nums), total_sum // 2)
