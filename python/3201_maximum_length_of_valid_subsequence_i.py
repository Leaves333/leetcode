class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        
        evens, odds = 0, 0
        for x in nums:
            if x % 2 == 0:
                evens += 1
            else:
                odds += 1

        oddfirst, evenfirst = 0, 0
        looking_for_odd = True
        looking_for_even = True
        for x in nums:
            if x % 2 == 0:
                if not looking_for_odd:
                    oddfirst += 1
                    looking_for_odd = not looking_for_odd
                if looking_for_even:
                    evenfirst += 1
                    looking_for_even = not looking_for_even
            else:
                if looking_for_odd:
                    oddfirst += 1
                    looking_for_odd = not looking_for_odd
                if not looking_for_even:
                    evenfirst += 1
                    looking_for_even = not looking_for_even

        return max([evens, odds, oddfirst, evenfirst])