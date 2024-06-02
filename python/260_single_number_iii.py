class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:

        xor = 0
        for n in nums:
            xor ^= n

        diff_idx = 0
        while not xor & 1 << diff_idx:
            diff_idx += 1
        
        first = xor
        second = xor
        for n in nums:
            if n & 1 << diff_idx:
                first ^= n
            else:
                second ^= n

        return [first, second]