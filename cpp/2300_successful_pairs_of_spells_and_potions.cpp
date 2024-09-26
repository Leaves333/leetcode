#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

		vector<int> ans;
		potions.push_back(INT_MAX);
		sort(potions.begin(), potions.end());
		reverse(potions.begin(), potions.end());

		for (int x : spells) {
			int low = 0, high = potions.size() - 1;
			while (low < high) {
				int mid = low + (high - low + 1) / 2;
				if ((long long) x * potions[mid] >= success) {
					low = mid;
				} else {
					high = mid - 1;
				}
			}
			ans.push_back(low);
		}

		return ans;
    }
};
