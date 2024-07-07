class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:

        ans = 0

        n = len(nums)
        seen_subsequences = set()

        for i in range(n - ans):
            seen_mods = set()
            for j in range(i + 1, n - ans):

                if (i, j) in seen_subsequences:
                    continue

                mod = (nums[i] + nums[j]) % k
                if mod in seen_mods:
                    continue

                cur_length = 2
                seen_subsequences.add((i, j))
                seen_mods.add(mod)
                last = j
                for cur in range(j + 1, n - ans):
                    if (nums[last] + nums[cur]) % k == mod:
                        seen_subsequences.add((last, cur))
                        last = cur
                        cur_length += 1

                ans = max(ans, cur_length)

        return ans