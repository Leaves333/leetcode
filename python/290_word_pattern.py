class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        words = s.split()
        map = dict()
        already_seen = set()

        if len(words) != len(pattern):
            return False

        for i in range(len(pattern)):
            if (not words[i] in map) and (not pattern[i] in already_seen):
                map[words[i]] = pattern[i]
                already_seen.add(pattern[i])
            else:
                if words[i] not in map or map[words[i]] != pattern[i]:
                    return False
            
        return True
