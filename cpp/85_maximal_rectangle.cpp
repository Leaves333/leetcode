#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        vvi dp_left(n, vi(m));
        vvi dp_top(n, vi(m));

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    cur++;
                else
                    cur = 0;
                dp_left[i][j] = cur;
            }
        }

        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1')
                    cur++;
                else
                    cur = 0;
                dp_top[i][j] = cur;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // calculate max area of rectangle with corner at i, j

                // build a min stack of heights
                stack<int> min_stack;
                for (int k = i; k > i - dp_left[i][j]; k--) {
                    if (min_stack.empty())
                        min_stack.push(dp_top[k][j]);
                    else
                        min_stack.push(min(min_stack.top(), dp_top[k][j]));
                }

                // try and go as high as possible
                int height = 0;
                int min_left = INT_MAX;
                while (min_stack.size() > 0) {
                    while (min_left >= min_stack.size() && j - height >= 0 && height < min_stack.top()) {
                        min_left = min(min_left, dp_left[i][j - height]);
                        height++;
                    }

                    int sz = (height - 1) * (int) min_stack.size();
                    cout << "size at " << i << ", " << j << " could be " << sz << endl;
                    ans = max(ans, (height - 1) * (int) min_stack.size());
                    min_stack.pop();
                }

            }
        }

        return ans;

    }
};
