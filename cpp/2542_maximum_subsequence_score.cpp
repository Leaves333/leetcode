#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

		vector<pair<int, int>> indices;
		for (int i = 0; i < nums1.size(); i++) {
			indices.push_back(make_pair(nums2[i], i));
		}
		sort(indices.begin(), indices.end());

		priority_queue<int, vector<int>, greater<int>> pq;
		long long sum = 0;
		for (int i = nums1.size() - 1; i >= nums1.size() - k + 1; i--) {
			pq.push(nums1[indices[i].second]);
			sum += nums1[indices[i].second];
		}

		long long ans = 0;
		for (int i = nums1.size() - k; i >= 0; i--) {
			pq.push(nums1[indices[i].second]);
			sum += nums1[indices[i].second];
			ans = max(ans, sum * indices[i].first);
			sum -= pq.top();
			pq.pop();
		}

		return ans;

    }
};
