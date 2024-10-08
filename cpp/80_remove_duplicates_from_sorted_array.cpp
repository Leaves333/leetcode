#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int left = 1;
		int seen = 1;
		for (int right = 1; right < nums.size(); right++) {
			if (nums[right] == nums[right - 1]) {
				seen++;
			} else {
				seen = 1;
			}
			if (seen <= 2) {
				nums[left] = nums[right];
				left++;
			}
		}
		return left;
    }
};
