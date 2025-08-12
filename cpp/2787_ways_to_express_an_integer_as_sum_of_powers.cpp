#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back(pow(i, x));
        }

        const int MOD = 1000000007;

        vector<int> dp(n + 1);
        dp[0] = 1;
        
        for (int i = 0; i < powers.size(); i++) {
            int val = powers[i];
            for (int j = n; j >= val; j--) {
                dp[j] += dp[j - val];
                dp[j] %= MOD;
            }
        }

        return dp[n];
    }
};
