from typing import List

class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        queue = sorted(intervals, key=lambda x : x.start)
        ans = 0
        next = []

        while len(queue) > 0:
            end_time = 0
            for interval in queue:
                if interval.start >= end_time:
                    end_time = interval.end
                else:
                    next.append(interval)
            queue = next
            next = []
            ans += 1

        return ans
