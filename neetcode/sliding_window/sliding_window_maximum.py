from collections import Counter

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
        seen = Counter()
        ans = []

        for i in range(len(nums)):
            seen[nums[i]] += 1
            if i >= k - 1:
                seen += Counter() # remove 0 count keys
                ans.append(max(seen))
                seen[nums[i - k + 1]] -= 1
            
        return ans