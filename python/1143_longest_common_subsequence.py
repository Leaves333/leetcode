class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        dp = [[0 for _ in range(len(text2))] for _ in range(len(text1))]
        
        for i in range(len(text1)):
            for j in range(len(text2)):

                if text1[i] == text2[j]:
                    dp[i][j] += 1
                    if i > 0 and j > 0:
                        dp[i][j] += dp[i - 1][j - 1]
                    continue

                cur = 0
                if i > 0:
                    cur = max(cur, dp[i - 1][j])
                if j > 0:
                    cur = max(cur, dp[i][j - 1])
                dp[i][j] += cur
        
        return dp[-1][-1]