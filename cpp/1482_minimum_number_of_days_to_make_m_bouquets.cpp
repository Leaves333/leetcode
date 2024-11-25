#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
		if ((long long) k * m > bloomDay.size()) {
			return -1;
		}
		int low = 1, high = 1000000000;
		while (low < high) {
			int mid = low + (high - low) / 2;
			
			int num_bouquets = 0;
			int streak = 0;
			for (int i = 0; i < bloomDay.size(); i++) {
				if (bloomDay[i] <= mid) {
					streak++;
				} else {
					streak = 0;
				}
				if (streak >= k) {
					streak = 0;
					num_bouquets++;
				}
			}

			if (num_bouquets >= m) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
    }
};
