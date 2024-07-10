class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        numbers = sorted(numbers)
        left, right = 0, len(numbers) - 1

        while left < right:
            x = numbers[left] + numbers[right]
            if x == target:
                return [left + 1, right + 1]
            elif x < target:
                left += 1
            else:
                right -= 1

        return -1