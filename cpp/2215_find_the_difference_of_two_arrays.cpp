#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> a, b;
		for (int x : nums1) {
			a.insert(x);
		}
		for (int x : nums2) {
			b.insert(x);
		}

		vector<vector<int>> ans;
		vector<int> first;
		for (int x : a) {
			if (b.count(x) == 0) {
				first.push_back(x);
			}
		}
		ans.push_back(first);

		vector<int> second;
		for (int x : b) {
			if (a.count(x) == 0) {
				second.push_back(x);
			}
		}
		ans.push_back(second);

		return ans;
    }
};
