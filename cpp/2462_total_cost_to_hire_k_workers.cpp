#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

		int left = candidates, right = costs.size() - 1;
		priority_queue<int, vector<int>, greater<int>> pq_left;
		priority_queue<int, vector<int>, greater<int>> pq_right;
		for (int i = 0; i < candidates; i++) {
			pq_left.push(costs[i]);
		}

		for (int i = 0; i < candidates; i++) {
			if (right < left) {
				break;
			}
			pq_right.push(costs[right]);
			right--;
		}

		pq_left.push(INT_MAX);
		pq_right.push(INT_MAX);

		long long ans = 0;
		for (int i = 0; i < k; i++) {
			int left_price = pq_left.top();
			int right_price = pq_right.top();
			if (left_price <= right_price) {
				pq_left.pop();
				ans += left_price;
				if (left <= right) {
					pq_left.push(costs[left]);
					left++;
				}
			} else {
				pq_right.pop();
				ans += right_price;
				if (right >= left) {
					pq_right.push(costs[right]);
					right--;
				}
			}
		}
		return ans;

    }
};
