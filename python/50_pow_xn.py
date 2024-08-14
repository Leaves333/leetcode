class Solution:

    def myPow(self, x: float, n: int) -> float:
        
        if x == 0:
            return 0

        seen = dict() 
        seen[0] = 1
        seen[1] = x
        seen[-1] = 1/x

        def solve(x: float, n: int) -> float:
            if n in seen:
                return seen[n]
            half = n // 2
            seen[n] = solve(x, half) * solve(x, n - half)
            return seen[n]

        return solve(x, n)
