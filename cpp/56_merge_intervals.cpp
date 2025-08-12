#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        for (auto interval : intervals) {
            if (ans.size() == 0) {
                ans.push_back(interval);
            } else {
                auto &last = ans.back();
                if (interval[0] <= last[1]) {
                    last[1] = max(last[1], interval[1]);
                } else {
                    ans.push_back(interval);
                }
            }
        }

        return ans;
    }
};
