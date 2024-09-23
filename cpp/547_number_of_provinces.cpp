#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        bool visited[isConnected.size()];
		memset(visited, false, sizeof(visited));
		
		int ans = 0;
		for (int i = 0; i < isConnected.size(); i++) {
			if (!visited[i]) {
				ans++;
				dfs(isConnected, visited, i);
			}
		}
		return ans;
    }

	void dfs(vector<vector<int>> &edges, bool visited[], int cur) {
		if (visited[cur]) {
			return;
		}
		visited[cur] = true;
		for (int i = 0; i < edges[cur].size(); i++) {
			if (edges[cur][i]) {
				dfs(edges, visited, i);
			}
		}
	}
};
