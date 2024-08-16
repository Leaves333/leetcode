from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        ans = []
        candidates = sorted(candidates)

        sum = 0
        cur = []

        def helper(i: int):

            # base cases
            nonlocal sum
            if sum > target:
                return
            if sum == target:
                ans.append(cur.copy())
                return
            if i >= len(candidates):
                return

            # include this num
            sum += candidates[i]
            cur.append(candidates[i])
            helper(i + 1)
            sum -= candidates[i]
            cur.pop()

            # skip this num
            i += 1
            while i < len(candidates) and candidates[i] == candidates[i - 1]:
                i += 1
            helper(i)

        helper(0)
        return ans
        
