class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        seen = set()
        i = 0
        while i < len(nums):
            if nums[i] in seen:
                nums.pop(i)
            else:
                seen.add(nums[i])
                i += 1
        return len(nums)