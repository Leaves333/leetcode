class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = [i for i in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i, min(len(nums), i + nums[i] + 1)):
                jumps[j] = min(jumps[j], jumps[i] + 1)
        return jumps[-1]