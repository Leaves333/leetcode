class Solution(object):
    def canConvertString(self, s, t, k):
        """
        :type s: str
        :type t: str
        :type k: int
        :rtype: bool
        """
        if len(s) != len(t):
            return False

        differences = dict()
        for i in range(26):
            differences[i] = 0
        
        for i in range(len(s)):
            diff = ord(t[i]) - ord(s[i])
            if diff < 0:
                diff += 26
            differences[diff] += 1

        for i in range(1, 26):
            num_shifts = k // 26
            if i <= k % 26:
                num_shifts += 1
            if differences[i] > num_shifts:
                return False
        return True