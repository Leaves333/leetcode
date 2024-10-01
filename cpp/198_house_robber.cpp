#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		vector<int> dp;
		dp.push_back(nums[0]);
		if (nums.size() > 1) {
			dp.push_back(max(nums[0], nums[1]));
		}
		for (int i = 2; i < nums.size(); i++) {
			dp.push_back(max(dp[i - 1], dp[i - 2] + nums[i]));
		}
		return dp[dp.size() - 1];
    }
};
