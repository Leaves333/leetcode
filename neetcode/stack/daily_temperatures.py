class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        ans = [0 for _ in range(len(temperatures))]
        stack = []

        for i in range(len(temperatures)):
            while len(stack) != 0 and stack[-1][0] < temperatures[i]:
                top = stack.pop()
                ans[top[1]] = i - top[1]
            stack.append((temperatures[i], i))

        return ans