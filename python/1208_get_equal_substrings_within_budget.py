class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:

        diff = [abs(ord(s[i]) - ord(t[i])) for i in range(len(s))]
        cur = 0
        left = 0
        right = 0
        ans = 0

        while right < len(s):
            cur += diff[right]
            if cur > maxCost:
                cur -= diff[left]
                left += 1
            else:
                ans = max(ans, right - left + 1)
            right += 1
        
        return ans