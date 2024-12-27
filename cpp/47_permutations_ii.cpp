#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		set<vector<int>> ans;
		permutations(ans, nums, 0);
		return vector<vector<int>>(ans.begin(), ans.end());
    }

	void permutations(set<vector<int>>& res, vector<int> cur, int idx) {
		if (idx == cur.size()) {
			res.insert(cur);
		}

		for (int i = idx; i < cur.size(); i++) {
			swap(cur[idx], cur[i]);
			permutations(res, cur, idx + 1);
			swap(cur[idx], cur[i]);
		}
	}
};
