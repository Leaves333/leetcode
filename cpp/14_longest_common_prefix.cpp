#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int smallest_idx = 0;
		for (int i = 1; i < strs.size(); i++) {
			if (strs[i].length() < strs[smallest_idx].length()) {
				smallest_idx = i;
			}
		}

		string ans;
		for (int i = 0; i < strs[smallest_idx].length(); i++) {
			bool good = true;
			for (int j = 0; j < strs.size(); j++) {
				if (strs[smallest_idx][i] != strs[j][i]) {
					good = false;
				}
			}
			if (!good) {
				break;
			}
			ans += strs[smallest_idx][i];
		}
		return ans;
    }
};
