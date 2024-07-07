class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        left = [nums[0]]
        for i in range(1, len(nums)):
            left.append(left[-1] * nums[i])

        right = [nums[-1]]
        for i in range(len(nums) - 2, -1, -1):
            right.append(right[-1] * nums[i])
        
        ans = []
        for i in range(len(nums)):
            if i == 0:
                ans.append(right[-2])
            elif i == len(nums) - 1:
                ans.append(left[-2])
            else:
                ans.append(left[i - 1] * right[-(i + 2)])
        return ans