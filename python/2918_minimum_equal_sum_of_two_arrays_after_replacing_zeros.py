from typing import List

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum_one = sum(nums1)
        sum_two = sum(nums2)
        zeroes_one = len([x for x in nums1 if x == 0])
        zeroes_two = len([x for x in nums2 if x == 0])

        if ((sum_one > sum_two or sum_one + zeroes_one > sum_two) and zeroes_two == 0):
            return -1
        if ((sum_two > sum_one or sum_two + zeroes_two > sum_one) and zeroes_one == 0):
            return -1
        return max(sum_one + zeroes_one, sum_two + zeroes_two)
