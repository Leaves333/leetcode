#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		unordered_map<char, char> map_s_to_t;
		unordered_map<char, char> map_t_to_s;

		for (int i = 0; i < s.length(); i++) {
			if (map_s_to_t.count(s[i]) == 0 && map_t_to_s.count(t[i]) == 0) {
				map_s_to_t[s[i]] = t[i];
				map_t_to_s[t[i]] = s[i];
			} else {
				if (map_s_to_t[s[i]] != t[i] || map_t_to_s[t[i]] != s[i]) {
					return false;
				}
			}
		}
		return true;
    }
};
