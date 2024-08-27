#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

		sort(coins.begin(), coins.end());
		int dp[amount + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		for (int coin : coins) {
			if (coin > amount) {
				continue;;
			}
			dp[coin] = 2;
			for (int i = coin + 1; i < amount + 1; i++) {
				if (dp[i - coin] != 0) {
					if (dp[i] == 0) {
						dp[i] = dp[i - coin] + 1;
					} else {
						dp[i] = min(dp[i], dp[i - coin] + 1);
					}
				}
			}
		}

		if (dp[amount] == 0) {
			return -1;
		}
		return dp[amount] - 1;

    }
};
