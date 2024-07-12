import collections

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        first = collections.Counter(s1)
        queue = []

        for i in range(len(s2)):
            queue.append(s2[i])
            if len(queue) >= len(s1):
                substring = "".join(queue)
                second = collections.Counter(substring)
                if second == first:
                    return True
                queue.pop(0)

        return False