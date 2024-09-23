#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
		map<vector<int>, int> dict;
		for (auto row : grid) {
			dict[row] += 1;
		}

		int ans = 0;
		for (int j = 0; j < grid.size(); j++) {
			vector<int> cur;
			for (int i = 0; i < grid.size(); i++) {
				cur.push_back(grid[i][j]);
			}
			ans += dict[cur];
		}
		return ans;
    }
};
