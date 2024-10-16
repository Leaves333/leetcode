#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		bool pushed = false;

		for (int i = 0; i < intervals.size(); i++) {
			int cur_left = intervals[i][0];
			int cur_right = intervals[i][1];

			if (cur_right < newInterval[0]) {
				result.push_back(intervals[i]);
			} else if (cur_left > newInterval[1]) {
				if (!pushed) {
					result.push_back(newInterval);
					pushed = true;
				}
				result.push_back((intervals[i]));
			} else {
				newInterval[0] = min(newInterval[0], cur_left);
				newInterval[1] = max(newInterval[1], cur_right);
			}
		}

		if (!pushed) {
			result.push_back(newInterval);
		}
		return result;
    }
};
