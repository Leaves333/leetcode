class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)

        ans = 0
        for n in nums:
            if n - 1 not in nums:
                cur_ans = 1
                while n + cur_ans in nums:
                    cur_ans += 1
                ans = max(ans, cur_ans)

        return ans