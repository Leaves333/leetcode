class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        seen = dict()
        for n in nums:
            if n not in seen:
                seen[n] = 0
            seen[n] += 1
        
        for key in seen:
            if seen[key] > len(nums) // 2:
                return key
        return -1