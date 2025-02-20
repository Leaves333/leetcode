#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        vvi dp(n, vi(m));

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    cur++;
                else
                    cur = 0;
                dp[i][j] = cur;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int smol = INT_MAX;
                for (int k = j; k < n; k++) {
                    smol = min(smol, dp[k][i]);
                    int box = (k - j + 1) * smol;
                    ans = max(ans, (k - j + 1) * smol);
                }
            }
        }
        return ans;

    }
};
