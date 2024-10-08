#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0, right = 0, sum = 0;
		int ans = INT_MAX;
		while (right < nums.size()) {
			if (sum < target) {
				sum += nums[right];
				right++;
			} else {
				ans = min(ans, right - left);
				sum -= nums[left];
				left++;
			}
		}

		while (sum >= target && left < right) {
			ans = min(ans, right - left);
			sum -= nums[left];
			left++;
		}
		return ans == INT_MAX ? 0 : ans;
    }
};
