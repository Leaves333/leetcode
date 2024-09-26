#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}

		int iterations = 0;
		bool iterated = false;
		while (q.size() > 0) {

			iterated = true;
			iterations++;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
					grid[x + 1][y] = 2;
					q.push(make_pair(x + 1, y));
				}
				if (x - 1 >= 0 && grid[x - 1][y] == 1) {
					grid[x - 1][y] = 2;
					q.push(make_pair(x - 1, y));
				}
				if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
					grid[x][y + 1] = 2;
					q.push(make_pair(x, y + 1));
				}
				if (y - 1 >= 0 && grid[x][y - 1] == 1) {
					grid[x][y - 1] = 2;
					q.push(make_pair(x, y - 1));
				}
			}
		}

		for (auto row : grid) {
			for (auto x : row) {
				if (x == 1) {
					return -1;
				}
			}
		}
		return iterations - iterated;
    }
};
