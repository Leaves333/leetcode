#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		int dist[maze.size()][maze[0].size()];
		for (int i = 0; i < maze.size(); i++) {
			for (int j = 0; j < maze[0].size(); j++) {
				dist[i][j] = INT_MAX;
			}
		}
		dist[entrance[0]][entrance[1]] = 0;

		queue<pair<int, int>> q;
		q.push(make_pair(entrance[0], entrance[1]));
		while (q.size() > 0) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x + 1 < maze.size() && dist[x + 1][y] > dist[x][y] + 1 && maze[x + 1][y] == '.') {
				dist[x + 1][y] = dist[x][y] + 1;
				q.push(make_pair(x + 1, y));
			}
			if (x - 1 >= 0 && dist[x - 1][y] > dist[x][y] + 1 && maze[x - 1][y] == '.') {
				dist[x - 1][y] = dist[x][y] + 1;
				q.push(make_pair(x - 1, y));
			}
			if (y + 1 < maze[0].size() && dist[x][y + 1] > dist[x][y] + 1 && maze[x][y + 1] == '.') {
				dist[x][y + 1] = dist[x][y] + 1;
				q.push(make_pair(x, y + 1));
			}
			if (y - 1 >= 0 && dist[x][y - 1] > dist[x][y] + 1 && maze[x][y - 1] == '.') {
				dist[x][y - 1] = dist[x][y] + 1;
				q.push(make_pair(x, y - 1));
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < maze[0].size(); i++) {
			if (0 != entrance[0] || i != entrance[1]) {
				ans = min(ans, dist[0][i]);
			}
			if (maze.size() - 1 != entrance[0] || i != entrance[1]) {
				ans = min(ans, dist[maze.size() - 1][i]);
			}
		}
		for (int i = 0; i < maze.size(); i++) {
			if (i != entrance[0] || 0 != entrance[1]) {
				ans = min(ans, dist[i][0]);
			}
			if (i != entrance[0] || maze[0].size() - 1 != entrance[1]) {
				ans = min(ans, dist[i][maze[0].size() - 1]);
			}
		}
		return ans == INT_MAX ? -1 : ans;

    }
};
