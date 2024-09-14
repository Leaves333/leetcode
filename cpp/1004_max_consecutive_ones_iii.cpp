#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
		int left = -1, right = 0, ans = 0, cur = 0;
		while (right < nums.size()) {
			if (nums[right] == 0) {
				cur++;
				if (cur > k) {
					while (true) {
						left++;
						if (nums[left] == 0) {
							break;
						}
					}
				}
			}
			ans = max(ans, right - left);
			right++;
		}
		return ans;
    }
};
