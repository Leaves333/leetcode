#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
		int shorter = min(word1.length(), word2.length());
		string ans;
		for (int i = 0; i < shorter; i++) {
			ans += word1[i];
			ans += word2[i];
		}

		if (word1.length() == shorter) {
			ans += word2.substr(shorter, word2.length() - shorter);
		} else if (word2.length() == shorter) {
			ans += word1.substr(shorter, word1.length() - shorter);
		}

		return ans;
    }
};
