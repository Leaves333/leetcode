class Solution:
    def numSteps(self, s: str) -> int:
        ans = 0
        num = int(s, 2)
        while num > 1:
            if num & 1:
                num += 1
            else:
                num = num >> 1
            ans += 1
        return ans