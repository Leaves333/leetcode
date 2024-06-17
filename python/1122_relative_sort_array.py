class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        seen = dict()
        for x in arr1:
            if x not in seen:
                seen[x] = 0
            seen[x] += 1

        ans = []
        for x in arr2:
            if x in seen:
                for _ in range(seen.pop(x)):
                    ans.append(x)

        for key in sorted(seen.keys()):
            for _ in range(seen[key]):
                ans.append(key)

        return ans