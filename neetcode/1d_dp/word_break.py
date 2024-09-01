from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        cache = {}
        def helper(s):

            if len(s) == 0:
                return True
            if s in cache:
                return cache[s]

            ans = False
            for word in wordDict:
                if len(s) >= len(word) and s[:len(word)] == word:
                    ans = ans or helper(s[len(word):])
                    if ans:
                        cache[s] = True
                        return True

            cache[s] = ans
            return ans

        return helper(s)
