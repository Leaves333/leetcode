class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        
        ans = ''
        queue = []
        
        for i in range(len(s)):
            if s[i] == '1':
                queue.append(i)
                if len(queue) >= k:
                    left = queue.pop(0)
                    right = i + 1
                    if len(ans) == 0 or right - left < len(ans):
                        ans = s[left:right]
                    elif len(ans) == right - left:
                        ans = min(s[left:right], ans)

        return ans