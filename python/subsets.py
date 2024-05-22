class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ans = []
        for i in range(2 ** len(nums)):
            cur_subset = []
            for j in range(len(nums)):
                if i & 1 << j:
                    cur_subset.append(nums[j])
            ans.append(cur_subset)
        return ans
