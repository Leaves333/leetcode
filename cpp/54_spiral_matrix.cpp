#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> ans;
		if (matrix.size() == 1) {
			return matrix[0];
		} else if (matrix[0].size() == 1) {
			for (int i = 0; i < matrix.size(); i++) {
				ans.push_back(matrix[i][0]);
			}
			return ans;
		}

		int direction = 0; // 0=right, 1=down, 2=left, 3=up
		bool visited[matrix.size()][matrix[0].size()];
		memset(visited, false, sizeof(visited));

		int x = 0, y = 0;
		bool turned = false;
		while (true) {

			if (visited[x][y]) {
				break;
			}
			visited[x][y] = true;
			ans.push_back(matrix[x][y]);

			if (direction == 0) {
				if (y + 1 < matrix[0].size() && !visited[x][y + 1]) {
					y++;
				} else {
					direction = (direction + 1) % 4;
					x++;
				}
			} else if (direction == 1) {
				if (x + 1 < matrix.size() && !visited[x + 1][y]) {
					x++;
				} else {
					direction = (direction + 1) % 4;
					y--;
				}
			} else if (direction == 2) {
				if (y > 0 && !visited[x][y - 1]) {
					y--;
				} else {
					direction = (direction + 1) % 4;
					x--;
				}
			} else if (direction == 3) {
				if (x > 0 && !visited[x - 1][y]) {
					x--;
				} else {
					direction = (direction + 1) % 4;
					y++;
				}
			}
		}

		return ans;
    }
};
