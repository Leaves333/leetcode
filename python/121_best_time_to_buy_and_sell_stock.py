class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        small = [x for x in prices]
        for i in range(1, len(small)):
            small[i] = min(small[i], small[i - 1])
        return max([prices[i] - small[i] for i in range(len(small))])