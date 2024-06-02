class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        bits = [0 for _ in range(33)]
        for i in range(len(nums)):
            if nums[i] < 0:
                bits[-1] += 1
                nums[i] *= -1
            for j in range(32):
                if nums[i] & 1 << j:
                    bits[j] += 1
        
        ans = 0
        for i in range(32):
            if bits[i] % 3 == 1:
                ans += 1 << i
        if bits[-1] % 3 == 1:
            ans *= -1

        return ans