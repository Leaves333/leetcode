#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
		vector<int> res = vector<int>({0, 1});
		while (res.size() < n + 1) {
			cout << res.size() << endl;
			int s = res.size();
			for (int i = 0; i < s; i++) {
				res.push_back(res[i] + 1);
			}
		}
		while (res.size() > n + 1) {
			res.pop_back();
		}
		return res;
    }
};
