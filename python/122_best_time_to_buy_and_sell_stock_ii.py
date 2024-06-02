class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        ans = 0
        stock = -1

        for i in range(len(prices) - 1):
            if prices[i] < prices[i + 1] and stock == -1:
                stock = prices[i]
            if stock >= 0 and prices[i] > prices[i + 1]:
                ans += prices[i] - stock
                stock = -1
        if stock >= 0:
            ans += prices[-1] - stock

        return ans