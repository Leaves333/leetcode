class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        ans = []
        cur_list = []
        cur_sum = 0
        n = len(candidates)

        def backtracking(i):

            nonlocal ans, cur_list, cur_sum

            if cur_sum > target:
                return
            if cur_sum == target:
                ans.append(cur_list[::1])

            for k in range(i, n):
                cur_sum += candidates[k]
                cur_list.append(candidates[k])
                backtracking(k)
                cur_sum -= candidates[k]
                cur_list.pop()

        backtracking(0)
        return ans