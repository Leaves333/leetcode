from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        remaining = nums.copy()
        ans = []
        cur = []
        
        def helper():

            if len(remaining) == 0:
                ans.append(cur.copy())
                return

            n = len(remaining)
            for i in range(n):
                x = remaining[i]
                remaining.remove(x)
                cur.append(x)
                helper()
                cur.pop(-1)
                remaining.insert(i, x)

        helper()
        return ans
