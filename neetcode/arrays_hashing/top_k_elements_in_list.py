from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        sorted_by_frequency = sorted([(count[x], x) for x in count])
        return [x[1] for x in sorted_by_frequency[len(sorted_by_frequency) - k:]]