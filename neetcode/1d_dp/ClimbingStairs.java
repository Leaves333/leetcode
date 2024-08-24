class Solution {
	private int[] dp;

	public int climbStairs(int n) {
		dp = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			dp[i] = -1;
		}
		dp[0] = 1;
		dp[1] = 1;
		return helper(n);
	}

	private int helper(int n) {
		if (dp[n] != -1)
			return dp[n];
		int ans = helper(n - 1) + helper(n - 2);
		dp[n] = ans;
		return ans;
	}
}
