class Solution:
    def reverse(self, x: int) -> int:
        negative = False
        if x < 0:
            negative = True
            x *= -1
        if int(str(x)[::-1]) > (1 << 31) - 1:
            return 0
        else:
            return int(str(x)[::-1]) * pow(-1, negative)