#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		int right = intervals[0][1];
		int ans = 0;

		for (int i = 1; i < intervals.size(); i++) {
			vector<int> *cur = &intervals[i];
			if (cur->at(0) < right) {
				ans++;
				right = min(right, cur->at(1));
			} else {
				right = cur->at(1);
			}
		}
		return ans;
    }
};
