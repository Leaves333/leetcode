#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

		priority_queue<int, vector<int>, greater<int>> q;
		for (int x : nums) {
			q.push(x);
			if (q.size() > k) {
				q.pop();
			}
		}
		return q.top();

    }
};
