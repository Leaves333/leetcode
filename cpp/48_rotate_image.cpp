#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int max_layers = (n + 1) / 2;
		for (int layer = 0; layer < max_layers; layer++) {
			for (int i = 0; i < n - (2 * layer) - 1; i++) {
				pair<int, int> coords[4];
				coords[0] = make_pair(layer, layer + i);
				coords[1] = make_pair(layer + i, n - 1 - layer);
				coords[2] = make_pair(n - 1 - layer, n - 1 - i - layer);
				coords[3] = make_pair(n - 1 - i - layer, layer);

				int tmp = matrix[coords[0].first][coords[0].second];
				matrix[coords[0].first][coords[0].second] = matrix[coords[3].first][coords[3].second];
				matrix[coords[3].first][coords[3].second] = matrix[coords[2].first][coords[2].second];
				matrix[coords[2].first][coords[2].second] = matrix[coords[1].first][coords[1].second];
				matrix[coords[1].first][coords[1].second] = tmp;
			}
		}
    }
};
