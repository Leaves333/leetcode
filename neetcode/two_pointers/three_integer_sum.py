class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        ans = []
        seen = set()
        n = len(nums)
        nums = sorted(nums)

        for i in range(n):
            j, k = i + 1, n - 1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if total == 0:
                    s = sorted([nums[i], nums[j], nums[k]])
                    s = tuple(s)
                    if s not in seen:
                        seen.add(s)
                        ans.append([nums[i], nums[j], nums[k]])
                    j += 1
                elif total > 0:
                    k -= 1
                else:
                    j += 1

        return ans