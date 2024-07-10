class Solution:
    def isPalindrome(self, s: str) -> bool:
        sanitized = "".join([c for c in s.lower() if c.isalnum()])
        return sanitized == sanitized[::-1]