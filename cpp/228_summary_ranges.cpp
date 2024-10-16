#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if (nums.size() == 0) {
			return ans;
		}

		int left = nums[0], right = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int x = nums[i];
			if (x == right + 1) {
				right++;
			} else {
				if (left == right) {
					ans.push_back(to_string(left));
				} else {
					ans.push_back(to_string(left) + "->" + to_string(right));
				}

				left = x;
				right = x;
			}
		}

		if (left == right) {
			ans.push_back(to_string(left));
		} else {
			ans.push_back(to_string(left) + "->" + to_string(right));
		}
		return ans;
    }
};
