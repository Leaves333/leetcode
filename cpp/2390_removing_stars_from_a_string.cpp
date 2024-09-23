#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
		deque<char> stack;
		for (char c : s) {
			if (c == '*') {
				stack.pop_back();
			} else {
				stack.push_back(c);
			}
		}

		string ans = "";
		while (stack.size() > 0) {
			ans += stack.front();
			stack.pop_front();
		}

		return ans;
    }
};
