#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		bool dp[nums.size()];
		memset(dp, false, sizeof(dp));
		dp[0] = true;

		for (int i = 0; i < nums.size(); i++) {
			int dist = i;
			if (dp[i]) {
				dist = min((int) nums.size() - 1, i + nums[i]);
			}
			for (int j = i + 1; j <= dist; j++) {
				dp[j] = true;
			}
		}

		return dp[nums.size() - 1];
    }
};
