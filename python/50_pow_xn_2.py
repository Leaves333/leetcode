class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0

        exp = 1.0
        if n < 0:
            x = 1 / x
            n *= -1

        while n > 0:
            if n % 2 == 1:
                exp *= x
                n -= 1
            else:
                x *= x
                n = n // 2
        return exp
