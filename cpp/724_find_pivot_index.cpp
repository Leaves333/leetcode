#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
		vector<int> prefix_sum;
		prefix_sum.push_back(0);
		for (int x : nums) {
			prefix_sum.push_back(prefix_sum[prefix_sum.size() - 1] + x);
		}
		for (int i = 1; i < prefix_sum.size(); i++) {
			if (prefix_sum[i - 1] == prefix_sum[prefix_sum.size() - 1] - prefix_sum[i]) {
				return i - 1;
			}
		}
		return -1;
    }
};
