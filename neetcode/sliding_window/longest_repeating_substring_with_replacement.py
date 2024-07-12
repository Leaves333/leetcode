class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
       
        seen = {x:0 for x in "QWERTYUIOPASDFGHJKLZXCVBNM"}
        left, right = 0, 0
        
        def good() -> bool:
            largest = 0
            total = 0
            for x in seen.values():
                total += x
                largest = max(x, largest)
            return total - largest <= k

        ans = 0
        while right < len(s):
            seen[s[right]] += 1
            right += 1
            while not good():
                seen[s[left]] -= 1
                left += 1
            ans = max(ans, right - left)

        return ans