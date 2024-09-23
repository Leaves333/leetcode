#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

		int left = -1, right = 0;
		int ans = 0;
		bool seen_zero = false;

		while (right < nums.size()) {
			if (nums[right] != 1) {
				if (!seen_zero) {
					seen_zero = true;
				} else {
					left++;
					while (nums[left] != 0) {
						left++;
					}
				}
			}
			ans = max(ans, right - left - 1);
			right++;
		}

		return ans;

    }
};
