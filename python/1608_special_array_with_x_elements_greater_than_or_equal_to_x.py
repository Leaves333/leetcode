class Solution:
    def specialArray(self, nums: List[int]) -> int:

        count = {}
        for x in nums:
            if x not in count:
                count[x] = 0
            count[x] += 1

        cur = len(nums)
        for i in range(len(nums) + 1):
            if cur == i:
                return cur
            if i in count:
                cur -= count[i]
        return -1