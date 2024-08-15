from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        ans = []
        cur = []

        def helper(i : int):

            if i >= len(nums):
                ans.append(cur.copy())
                return

            # don't add this element
            helper(i + 1)

            # add this element
            cur.append(nums[i])
            helper(i + 1)
            cur.pop(-1)

        helper(0)
        return ans

