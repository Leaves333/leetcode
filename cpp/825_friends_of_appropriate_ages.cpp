#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
		map<int, int> freq;
		for (int x : ages) {
			freq[x]++;
		}

		int ans = 0;
		int friends = 0;
		auto left = freq.begin();
		for (auto right = freq.begin(); right != freq.end(); right++) {
			friends += right->second;
			while (left->first <= right->first / 2 + 7 && left != freq.end()) {
				friends -= left->second;
				left++;
			}
			ans += max(0, (friends - 1)) * right->second;
		}
		return ans;
    }
};
