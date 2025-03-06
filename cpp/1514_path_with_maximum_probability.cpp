#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0.0);

        prob[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1, start_node));

        vector<vector<pair<int, double>>> adj_list(n);
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj_list[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }

        while (!pq.empty()) {
            double cur_prob = pq.top().first;
            int cur_loc = pq.top().second;
            pq.pop();
            for (auto e : adj_list[cur_loc]) {
                double new_prob = cur_prob * e.second;
                if (new_prob > prob[e.first]) {
                    prob[e.first] = new_prob;
                    pq.push(make_pair(new_prob, e.first));
                }
            }
        }

        return prob[end_node];
    }
};
