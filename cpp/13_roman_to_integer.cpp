#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> kValues = {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000},
};

class Solution {
public:
    int romanToInt(string s) {
		int ans = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == 'I' && s[i + 1] == 'V' ||
				s[i] == 'I' && s[i + 1] == 'X' ||
				s[i] == 'X' && s[i + 1] == 'L' ||
				s[i] == 'X' && s[i + 1] == 'C' ||
				s[i] == 'C' && s[i + 1] == 'D' ||
				s[i] == 'C' && s[i + 1] == 'M') {
				ans -= kValues[s[i]];
			} else {
				ans += kValues[s[i]];
			}
		}
		ans += kValues[s[s.length() - 1]];
		return ans;
    }
};
