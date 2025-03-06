#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> final_pos;
        long long MOD = 1000000007;
        for (int i = 0; i < nums.size(); i++) {
            if (s[i] == 'R') {
                final_pos.push_back((long long) nums[i] + d);
            } else {
                final_pos.push_back((long long) nums[i] - d);
            }
        }
        sort(final_pos.begin(), final_pos.end());
        long long ans = 0;
        long long sum = final_pos[0];
        for (int i = 1; i < final_pos.size(); i++) {
            long long right = (i * final_pos[i]) % MOD;
            ans += (right + MOD - sum);
            ans %= MOD;
            sum += final_pos[i];
            sum %= MOD;
        }
        return ans;
    }
};
