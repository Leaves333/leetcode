from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        ans = []
        i = 0

        while i < len(intervals):

            # is interval first element
            if i == 0 and newInterval[1] < intervals[i][0]:
                ans.append(newInterval)
                ans.append(intervals[i])

            # is it the last element
            elif i == len(intervals) - 1 and newInterval[0] > intervals[-1][1]:
                ans.append(intervals[i])
                ans.append(newInterval)

            # does it not intersect at all
            elif i != 0:

                if intervals[i - 1][1] < newInterval[0] and newInterval[1] < intervals[i][0]:
                    ans.append(newInterval)
                    ans.append(intervals[i])

                # does it intersect
                elif intervals[i - 1][1] >= newInterval[0]:
                    while intervals[i][0] < newInterval[1]:
                        ans[-1][1] = max(newInterval[1], intervals[i][1])
                        i += 1

            else:
                ans.append(intervals[i])

            i += 1


        return ans
