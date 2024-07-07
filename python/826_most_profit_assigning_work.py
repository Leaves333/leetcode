class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):

        ordered = [(difficulty[i], i) for i in range(len(difficulty))]
        ordered.append((0, 0))
        ordered.sort()
        breakpoints = [[x[0], profit[x[1]]] for x in ordered]
        breakpoints[0] = (0, 0)

        for i in range(1, len(breakpoints)):
            breakpoints[i][1] = max(breakpoints[i - 1][1], breakpoints[i][1])

        ans, idx = 0, 0
        worker.sort()
        for x in worker:
            while idx < len(breakpoints) - 1 and breakpoints[idx + 1][0] <= x:
                idx += 1
            ans += breakpoints[idx][1]
        return ans