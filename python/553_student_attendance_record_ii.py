class Solution:
    def checkRecord(self, n: int) -> int:

        MOD = 1000000007
        # length - 1, absences, lates
        dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(n)]
        dp[0][0][0] = 1
        dp[0][1][0] = 1
        dp[0][0][1] = 1

        for i in range(1, n):

            # add an P
            for j in range(2):
                dp[i][j][0] += (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2]) % MOD

            # add an A
            dp[i][1][0] += (dp[i - 0][0][0] + dp[i - 0][0][1] + dp[i - 0][0][2]) % MOD

            # add an L
            for j in range(2):
                for k in range(2):
                    dp[i][j][k + 1] += dp[i - 1][j][k]

            for j in range(2):
                for k in range(3):
                    dp[i][j][k] %= MOD

        print(dp)
        ans = 0
        for j in range(2):
            for k in range(3):
                ans += dp[-1][j][k]
        return ans % MOD