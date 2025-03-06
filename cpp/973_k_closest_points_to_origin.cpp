#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool comp(const vector<int> &left, const vector<int> &right) {
    return (left[0] * left[0] + left[1] * left[1]) <
    (right[0] * right[0] + right[1] * right[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};
