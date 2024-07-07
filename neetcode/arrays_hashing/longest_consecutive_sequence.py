class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        
        ans = 0
        for n in nums:
            if n - 1 in nums:
                continue
            k = 1
            while n + k in nums:
                k += 1
            ans = max(ans, k)

        return ans