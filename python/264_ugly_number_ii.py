class Solution:
    def nthUglyNumber(self, n: int) -> int:
        nums = [1]
        a, b, c = 0, 0, 0
        for _ in range(n - 1):
            next_num = min(nums[a] * 2, nums[b] * 3, nums[c] * 5)
            if next_num == nums[a] * 2: a += 1
            if next_num == nums[b] * 3: b += 1
            if next_num == nums[c] * 5: c += 1
            nums.append(next_num)
        return nums[-1]