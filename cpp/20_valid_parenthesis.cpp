#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> stack;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{') {
				stack.push(c);
			} else {
				if (stack.size() == 0) {
					return false;
				}
				char top = stack.top();
				if (c == ')' && top != '(') {
					return false;
				} else if (c == ']' && top != '[') {
					return false;
				} else if (c == '}' && top != '{') {
					return false;
				}
				stack.pop();
			}
		}
		return stack.size() == 0;
    }
};
