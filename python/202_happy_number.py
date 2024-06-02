class Solution:
    def isHappy(self, n: int) -> bool:

        seen = set()
        def solve(n):
            if n == 1:
                return True
            if n in seen:
                return False
            seen.add(n)
            return solve(sum([int(x) ** 2 for x in str(n)]))
        
        return solve(n)