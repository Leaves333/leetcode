class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = dict()
        for s in strs:
            sorted_s = "".join(sorted(s))
            if sorted_s not in groups:
                groups[sorted_s] = []
            groups[sorted_s].append(s)
        return list(groups.values())