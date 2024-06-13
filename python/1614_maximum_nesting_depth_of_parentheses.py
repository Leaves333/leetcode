class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, cur = 0, 0
        for char in s:
            if char == '(':
                cur += 1
                ans = max(ans, cur)
            elif char == ')':
                cur -= 1
        return ans