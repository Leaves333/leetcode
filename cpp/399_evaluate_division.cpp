#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		unordered_map<string, vector<pair<string, double>>> edges;
		for (int i = 0; i < equations.size(); i++) {

			string a = equations[i][0];
			string b = equations[i][1];

			if (edges.count(a) == 0) {
				edges[a] = vector<pair<string, double>>();
			}
			if (edges.count(b) == 0) {
				edges[b] = vector<pair<string, double>>();
			}
			edges[a].push_back(make_pair(b, values[i]));
			edges[b].push_back(make_pair(a, 1 / values[i]));

		}

		vector<double> ans;
		for (auto query : queries) {

			// is the var declared
			string start = query[0];
			string end = query[1];
			if (edges.count(start) == 0 || edges.count(end) == 0) {
				ans.push_back(-1);
				continue;
			}

			// dfs from start to end
			stack<pair<string, double>> s;
			unordered_set<string> visited;
			bool found = false;

			s.push(make_pair(start, 1.0));
			while (s.size() > 0) {

				string pos = s.top().first;
				double value = s.top().second;
				s.pop();

				visited.insert(pos);
				if (pos == end) {
					ans.push_back(value);
					found = true;
					break;
				}

				for (auto dest : edges[pos]) {
					if (visited.count(dest.first) == 0) {
						s.push(make_pair(dest.first, value * dest.second));
					}
				}
			}
			
			if (!found) {
				ans.push_back(-1);
			}
		}

		return ans;

    }
};
