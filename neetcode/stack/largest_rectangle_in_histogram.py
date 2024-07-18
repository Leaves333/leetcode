class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        ans = 0
        stack = []  # index, height

        for i, h in enumerate(heights):
            start = i
            while len(stack) != 0 and h < stack[-1][1]:
                top = stack.pop()
                start = top[0]
            stack.append((start, h))
            for bar in stack:
                ans = max(ans, (i - bar[0] + 1) * bar[1])
        
        for bar in stack:
                ans = max(ans, (i - bar[0] + 1) * bar[1])

        return ans