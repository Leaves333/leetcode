from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        s = sorted([p[0] ** 2 + p[1] ** 2, p[0], p[1]] for p in points)
        return [[x[1], x[2]] for x in s[:k]] 
