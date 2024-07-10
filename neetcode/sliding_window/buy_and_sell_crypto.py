class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        ans = 0
        cheapest = 0

        for i in range(1, len(prices)):
            if prices[i] < prices[cheapest]:
                cheapest = i
            else:
                ans = max(ans, prices[i] - prices[cheapest])

        return ans