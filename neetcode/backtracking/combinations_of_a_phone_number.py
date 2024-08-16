from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        # edge case
        if len(digits) == 0:
            return []

        chars = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        
        def backtracking(digits: str) -> List[str]:

            if len(digits) == 1:
                return [c for c in chars[digits]]
            
            ans = []
            remaining = backtracking(digits[1:])
            for c in chars[digits[0]]:
                for r in remaining:
                    ans.append(c + r)

            return ans

        return backtracking(digits)
