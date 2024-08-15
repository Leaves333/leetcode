from typing import List

class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
       
        nums = sorted(nums)

        ans = []
        sum = 0
        cur = []

        def helper(i : int):
            nonlocal sum

            # base cases
            if i >= len(nums):
                return
            if sum > target:
                return
            if sum == target:
                ans.append(cur.copy())
                return

            # include this num
            sum += nums[i]
            cur.append(nums[i])
            helper(i)
            sum -= nums[i]
            cur.pop(-1)

            # don't include this num
            helper(i + 1)

        helper(0)
        return ans
