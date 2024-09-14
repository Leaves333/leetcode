from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort(key = lambda x : x[0])

        ans = []
        ans.append(intervals[0])

        for i in range(len(intervals)):
            cur = intervals[i]
            if ans[-1][1] >= cur[0]:
                ans[-1][1] = max(ans[-1][1], cur[1])
            else:
                ans.append(cur)

        return ans
        
