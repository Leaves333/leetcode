from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        ans = ""
        required = Counter(t)
        seen = Counter()
        left, right = 0, 0

        while right < len(s):

            seen[s[right]] += 1
            right += 1

            while seen >= required:
                substr = s[left:right]
                if len(substr) < len(ans) or ans == "":
                    ans = substr
                seen[s[left]] -= 1
                left += 1

        return ans