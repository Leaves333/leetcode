class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        letters = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        cur_str = ""

        def recur(i):
            nonlocal cur_str
            if i >= len(digits):
                ans.append(cur_str)
                return

            possibilities = letters[int(digits[i]) - 2]
            for letter in possibilities:
                cur_str += letter
                recur(i + 1)
                cur_str = cur_str[:-1]
        if len(digits) > 0:
            recur(0)
        
        return ans