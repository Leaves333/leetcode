#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if (haystack.length() < needle.length()) {
			return -1;
		}
		for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
			string substr = haystack.substr(i, needle.length());
			if (substr == needle) {
				return i;
			}
		}
		return -1;
    }
};
