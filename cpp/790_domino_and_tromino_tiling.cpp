#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
		vector<int> dp;
		dp.push_back(1);
		dp.push_back(2);
		dp.push_back(5);

		const int MOD = 1000000007;
		long long prefix = 0;
		for (int i = 3; i < n; i++) {
			prefix += 2 * dp[i - 3];
			prefix %= MOD;
			long long ways = 2 + dp[i - 1] + dp[i - 2]; // unique tilings of length i
			ways += prefix;
			dp.push_back(ways % MOD);
		}
		return dp[n - 1];
    }
};
