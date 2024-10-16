#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		int first[26], second[26];
		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));
		
		for (int i = 0; i < s.length(); i++) {
			first[s[i] - 'a']++;
		}
		for (int i = 0; i < t.length(); i++) {
			second[t[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (first[i] != second[i]) {
				return false;
			}
		}
		return true;
    }
};
