class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        
        num = 1
        ans = 0
        a, b = max(red, blue), min(red, blue)

        while a >= 0 and b >= 0:
            if ans % 2 == 0:
                a -= num
            else:
                b -= num
            num += 1
            ans += 1

        b, a = max(red, blue), min(red, blue)
        ans2 = 0
        num = 1
        while a >= 0 and b >= 0:
            if ans2 % 2 == 0:
                a -= num
            else:
                b -= num
            num += 1
            ans2 += 1


        return max(ans, ans2) - 1