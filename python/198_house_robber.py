class Solution:
    def rob(self, nums: List[int]) -> int:

        dp = [nums[0]]
        if len(nums) > 1:
            dp.append(max(nums[0], nums[1]))

        for i in range(2, len(nums)):
            dp.append(max(nums[i] + dp[i - 2], dp[i - 1]))

        return dp[-1]