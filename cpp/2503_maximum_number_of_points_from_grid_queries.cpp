#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dist[0][0] = grid[0][0];
        int changes[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto c : changes) {
                int new_x = cur.first + c[0];
                int new_y = cur.second + c[1];
                if (new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size())
                    continue;
                if (dist[cur.first][cur.second] < dist[new_x][new_y]) {
                    dist[new_x][new_y] = max(dist[cur.first][cur.second], grid[new_x][new_y]);
                    q.push({new_x, new_y});
                }
            }
        }

        vector<int> psum(1000001);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                psum[dist[i][j]]++;
            }
        }

        for (int i = 1; i < psum.size(); i++) {
            psum[i] += psum[i-1];
        }

        vector<int> ans;
        for (auto x : queries) {
            ans.push_back(psum[x-1]);
        }
        return ans;
    }
};
