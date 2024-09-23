#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> map;
		for (int x : arr) {
			if (map.count(x) == 0) {
				map[x] = 0;
			}
			map[x]++;
		}

		unordered_set<int> set;
		for (auto pair : map) {
			if (set.count(pair.second) != 0) {
				return false;
			}
			set.insert(pair.second);
		}

		return true;
    }
};
