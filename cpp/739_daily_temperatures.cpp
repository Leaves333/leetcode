#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

		vector<int> ans(temperatures.size(), 0);
		stack<int> s;

		for (int i = 0; i < temperatures.size(); i++) {
			while (s.size() > 0 && temperatures[i] > temperatures[s.top()]) {
				int x = s.top();
				ans[x] = i - x;
				s.pop();
			}
			s.push(i);
		}
		
		return ans;

    }
};
