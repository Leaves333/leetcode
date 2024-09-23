#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

		int dist[maze.size()][maze[0].size()];
		memset(dist, INT_MAX, sizeof(dist));
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
			if (y + 1 < maze.size() && dist[x][y + 1] > dist[x][y + 1] + 1 && maze[x][y + 1] == '.') {
				dist[x][y + 1] = dist[x][y + 1] + 1;
				q.push(make_pair(x, y + 1));
			}
			if (y - 1 >= 0 && dist[x][y - 1] > dist[x][y - 1] + 1 && maze[x][y - 1] == '.') {
				dist[x][y - 1] = dist[x][y - 1] + 1;
				q.push(make_pair(x, y - 1));
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < maze[0].size(); i++) {
			ans = max(ans, dist[0][i]);
			ans = max(ans, dist[maze.size() - 1][i]);
		}
		for (int i = 0; i < maze.size(); i++) {
			ans = max(ans, dist[i][0]);
			ans = max(ans, dist[i][maze[0].size() - 1]);
		}
		return ans == INT_MAX ? -1 : ans;

    }
};
