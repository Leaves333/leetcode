#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

		sort(points.begin(), points.end());

		int left_bound = points[0][1];
		int ans = 1;

		for (int i = 1; i < points.size(); i++) {
			auto &point = points[i];
			if (point[0] > left_bound) {
				ans++;
				left_bound = INT_MAX;
			}
			left_bound = min(left_bound, point[1]);
		}

		return ans;

    }
};
