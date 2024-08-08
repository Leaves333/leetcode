from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        first, second = Counter(ransomNote), Counter(magazine)
        return first <= second
