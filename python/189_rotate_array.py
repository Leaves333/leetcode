class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        copy = nums.copy()
        for i in range(len(nums)):
            nums[i] = copy[(i - k) % len(nums)]