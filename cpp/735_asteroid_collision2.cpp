#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> stack;
		for (int cur : asteroids) {
			if (cur < 0) {
				while (stack.size() > 0 && stack.back() > 0 && abs(cur) > stack.back()) {
					stack.pop_back();
				}
				if (stack.size() == 0 || stack.back() < 0) {
					stack.push_back(cur);
				} else if (abs(cur) == stack.back()) {
					stack.pop_back();
				}
			} else {
				stack.push_back(cur);
			}
		}
		return stack;
    }
};
