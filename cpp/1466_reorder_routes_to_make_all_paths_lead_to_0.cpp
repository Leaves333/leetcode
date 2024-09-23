#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

		vector<pair<int, bool>> edges[connections.size() + 1]; // dest, original order
		bool visited[connections.size() + 1];

		memset(visited, false, sizeof(visited));
		for (auto x : connections) {
			edges[x[0]].push_back(make_pair(x[1], true));
			edges[x[1]].push_back(make_pair(x[0], false));
		}

		int ans = 0;
		stack<int> s;
		s.push(0);
		while (s.size() > 0) {
			int cur = s.top();
			s.pop();

			visited[cur] = true;
			for (auto dest : edges[cur]) {
				if (!visited[dest.first]) {
					s.push(dest.first);
					if (dest.second) {
						ans++;
					}
				}
			}
		}

		return ans;

    }

};
