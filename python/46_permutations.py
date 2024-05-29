class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        used = set()
        ans = []
        cur_list = []

        def solve():
            nonlocal used, cur_list
            if len(used) == len(nums):
                ans.append(cur_list[::1])
                return
            for n in nums:
                if n not in used:
                    used.add(n)
                    cur_list.append(n)
                    solve()
                    used.remove(n)
                    cur_list.pop()

        solve()
        return ans