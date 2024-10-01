#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> cur;
		helper(k, n, ans, cur, 0, 1);
		return ans;
    }

	void helper(int k, int n, vector<vector<int>> &ans, vector<int> &cur, int cur_sum, int i) {
		if (cur_sum > n) {
			return;
		}
		if (cur_sum == n && cur.size() == k) {
			ans.push_back(vector<int>(cur.begin(), cur.end()));
			return;
		}
		if (cur.size() > k) {
			return;
		}
		if (i > 9) {
			return;
		}

		cur.push_back(i);
		helper(k, n, ans, cur, cur_sum + i, i + 1);
		cur.pop_back();
		helper(k, n, ans, cur, cur_sum, i + 1);
	}
};
