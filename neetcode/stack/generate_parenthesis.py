class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        ans = []
        
        def generate(cur, open, closed):
            if open == 0 and closed == 0:
                nonlocal ans
                ans.append(cur)
            if open > 0:
                generate(cur + '(', open - 1, closed)
            if closed > 0 and closed > open:
                generate(cur + ')', open, closed - 1)

        generate('', n, n)
        return ans