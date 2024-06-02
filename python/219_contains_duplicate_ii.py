class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = dict()
        for i in range(len(nums)):
            if nums[i] in seen:
                if abs(seen[nums[i]] - i) <= k:
                    return True
            seen[nums[i]] = i
        return False