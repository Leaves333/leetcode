#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		string rows[numRows];
		int cur = 0;
		bool adding = true;
		for (char c : s) {
			rows[cur] += c;
			if (adding) {
				cur++;
				if (cur >= numRows) {
					cur = numRows - 2;
					adding = false;
				}
			} else {
				cur--;
				if (cur < 0) {
					cur = 1;
					adding = true;
				}
			}
		}

		string ans;
		for (string s : rows) {
			ans += s;
		}
		return ans;
    }
};
