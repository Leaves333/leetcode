#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

		string ans = "";

		for (int i = 0; i < s.length(); i++) {
			int l = i, r = i;
			while (l >= 0 && r < s.length() && s[l] == s[r]) {
				int len = r - l + 1;
				if (len > ans.length()) {
					ans = s.substr(l, len);
				}
				l--;
				r++;
			}

			l = i, r = i - 1;
			while (l >= 0 && r < s.length() && s[l] == s[r]) {
				int len = r - l + 1;
				if (len > ans.length()) {
					ans = s.substr(l, len);
				}
				l--;
				r++;
			}
		}

		return ans;

    }
};
