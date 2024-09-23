#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

		stack<pair<string, int>> stack;
		stack.push(make_pair("", 1));

		for (int i = 0; i < s.length(); i++) {
			if (isdigit(s[i])) {
				int left_bracket_index = s.find('[', i);
				int times = stoi(s.substr(i, left_bracket_index - i));
				stack.push(make_pair("", times));
				i = left_bracket_index;
			}
			else if (s[i] == ']') {
				auto top = stack.top();
				stack.pop();
				for (int j = 0; j < top.second; j++) {
					stack.top().first += top.first;
				}
			}
			else {
				stack.top().first += s[i];
			}
		}

		return stack.top().first;
    }
};
