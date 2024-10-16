#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

		stack<string> s;
		for (string cur_token : tokens) {
			if (cur_token == "+") {
				int a = stoi(s.top());
				s.pop();
				int b = stoi(s.top());
				s.pop();
				s.push(to_string(a + b));
			} else if (cur_token == "-") {
				int a = stoi(s.top());
				s.pop();
				int b = stoi(s.top());
				s.pop();
				s.push(to_string(b - a));
			} else if (cur_token == "*") {
				int a = stoi(s.top());
				s.pop();
				int b = stoi(s.top());
				s.pop();
				s.push(to_string(a * b));
			} else if (cur_token == "/") {
				int a = stoi(s.top());
				s.pop();
				int b = stoi(s.top());
				s.pop();
				s.push(to_string(b / a));
			} else {
				s.push(cur_token);
			}
		}

		return stoi(s.top());

    }
};
