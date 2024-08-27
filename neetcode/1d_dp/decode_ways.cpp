#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	map<string, int> dp;
    int numDecodings(string s) {

		if (s[0] == '0') {
			return 0;
		}

		if (dp.count(s) > 0) {
			return dp[s];
		}

		if (s.length() <= 1) {
			return 1;
		}

		int ans = numDecodings(s.substr(1, s.length() - 1));
		int two_digit = stoi(s.substr(0, 2));
		if (two_digit >= 10 && two_digit <= 26) {
			ans += numDecodings(s.substr(2, s.length() - 2));
		}

		dp[s] = ans;
		return ans;

    }

};
