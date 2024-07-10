class Solution:
    def trap(self, height: List[int]) -> int:

        n = len(height)
        tallest_left = [0 for _ in range(n)]
        tallest_right = [0 for _ in range(n)]

        tallest_left[0] = height[0]
        tallest_right[-1] = height[-1]

        for i in range(1, n):
            tallest_left[i] = max(tallest_left[i - 1], height[i])
        for i in range(n - 2, -1, -1):
            tallest_right[i] = max(tallest_right[i + 1], height[i])
        
        left, right = 0, n - 1
        while left < n - 2 and tallest_left[left + 1] > tallest_left[left]:
            left += 1
        while right > 0 and tallest_right[right - 1] > tallest_right[right]:
            right -= 1

        ans = 0
        for i in range(left + 1, right):
            cur = min(tallest_left[i], tallest_right[i]) - height[i]
            cur = max(0, cur)
            ans += cur

        return ans