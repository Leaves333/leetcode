#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
		int dp[prices.size() + 1][2]; // 0 = no stock, 1 = has stock
		dp[0][0] = 0;
		dp[0][1] = INT_MIN;

		for (int i = 0; i < prices.size(); i++) {
			dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
			dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i] - fee);
		}

		return max(dp[prices.size()][0], dp[prices.size()][1]);
    }
};
