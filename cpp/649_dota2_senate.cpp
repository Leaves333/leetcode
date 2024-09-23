#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
		int r_to_skip = 0, d_to_skip = 0;
		int r = 0, d = 0;
		queue<char> senators;
		for (char c : senate) {
			senators.push(c);
			if (c == 'R') {
				r++;
			} else {
				d++;
			}
		}

		while (r > 0 && d > 0) {
			char cur = senators.front();
			senators.pop();
			if (cur == 'R') {
				if (r_to_skip > 0) {
					r--;
					r_to_skip--;
					continue;
				}
				d_to_skip++;
			} else {
				if (d_to_skip > 0) {
					d--;
					d_to_skip--;
					continue;
				}
				r_to_skip++;
			}
			senators.push(cur);
		}

		if (r <= 0) {
			return "Dire";
		} else {
			return "Radiant";
		}
    }
};
