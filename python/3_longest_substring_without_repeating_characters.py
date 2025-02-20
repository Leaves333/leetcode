class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        seen = set()
        l = 0
        r = 0
        ret = 0
        while (r < len(s)):
            while (s[r] in seen):
                seen.remove(s[l])
                l += 1
            seen.add(s[r])
            r += 1
            ret = max(ret, r - l)
        return ret
