from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
       
        nums = sorted(nums)
        subsets = []
        cur = []

        def helper(i: int):
            if i >= len(nums):
                subsets.append(cur.copy())
                return
            
            # include this num
            cur.append(nums[i])
            helper(i + 1)
            cur.pop()

            # if we don't include a num, we must skip to the next different num
            j = i + 1
            while j < len(nums) and nums[j] == nums[i]:
                j += 1
            helper(j)

        helper(0)
        return subsets
