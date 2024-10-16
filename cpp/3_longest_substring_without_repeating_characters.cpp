#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int left = 0, right = 0;
		int ans = 0;
		unordered_set<char> set;
		while (right < s.length()) {
			if (set.count(s[right]) > 0) {
				set.erase(s[left]);
				left++;
			} else {
				ans = max(ans, right - left + 1);
				set.insert(s[right]);
				right++;
			}
		}
		return ans;
    }
};
