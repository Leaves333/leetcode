class Solution:
    def isPalindrome(self, s: str) -> bool:
        parsed = "".join([c.lower() for c in s if c.isalnum()])
        return parsed == parsed[::-1]
