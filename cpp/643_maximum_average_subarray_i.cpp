#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		
		int big = sum;
		for (int i = k; i < nums.size(); i++) {
			sum += nums[i];
			sum -= nums[i - k];
			if (sum > big) {
				big = sum;
			}
		}
		return ((double) big) / k;
    }
};
