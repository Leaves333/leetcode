import math

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        
        if len(points) == 1: return 1 # edge case D:
        lines = dict() # slope, intercept

        for i in range(len(points)):
            for j in range(i + 1, len(points)):

                a = points[i]
                b = points[j]

                dx = a[0] - b[0]
                dy = a[1] - b[1]

                if dx == 0:
                    slope = "vert"
                    intercept = a[0]
                else:
                    slope = dy / dx
                    intercept = a[1] - (slope * a[0])

                if (slope, intercept) not in lines:
                    lines[(slope, intercept)] = set()
                lines[(slope, intercept)].add(i)
                lines[(slope, intercept)].add(j)
                
        ans = 0
        for key in lines:
            ans = max(ans, len(lines[key]))
        return ans