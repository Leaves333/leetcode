#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
		int low = 1, high = 1000000000;
		while (low < high) {
			int mid = low + (high - low) / 2;

			int time_taken = 0;
			for (int x : piles) {
				time_taken += x / mid;
				time_taken += x % mid != 0;
			}

			if (time_taken <= h) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
    }
};
