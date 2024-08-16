from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        cache = {}

        def helper(s: str) -> List[List[str]]:
            
            nonlocal cache
            if s in cache:
                return cache[s]
            if len(s) == 1:
                return [[s]]
            if len(s) == 0:
                return [[]]

            forwards, backwards = "", ""
            ans = []

            for i in range(len(s)):
                forwards += s[i]
                backwards = s[i] + backwards
                if forwards == backwards:
                    remaining = helper(s[i + 1:])
                    for r in remaining:
                        cur_list = [forwards]
                        cur_list.extend(r)
                        ans.append(cur_list.copy())

            cache[s] = ans
            return ans

        return helper(s)
