#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

		// initalize variables
		unsigned long long mask = 0;
		unsigned long long ALL_GOOD = ULLONG_MAX;

		int left = 0, right = 0;
		int target_counts[64];
		int current_counts[64];
		memset(target_counts, 0, sizeof(target_counts));
		memset(current_counts, 0, sizeof(current_counts));

		for (char c : t) {
			target_counts[c - 'A']++;
		}

		for (int i = 0; i < 64; i++) {
			if (current_counts[i] >= target_counts[i]) {
				mask |= (unsigned long long) 1 << i;
			}
		}

		// solve the problem
		pair<int, int> best_indices = { 0, INT_MAX };
		while (right < s.size()) {
			if (mask != ALL_GOOD) {
				int idx = ((int) s[right]) - 'A';
				current_counts[idx]++;
				right++;
				if (current_counts[idx] >= target_counts[idx]) {
					mask |= (unsigned long long) 1 << idx;
				}
			} else {
				if (right - left < best_indices.second - best_indices.first) {
					best_indices = make_pair(left, right);
				}
				int idx = ((int) s[left]) - 'A';
				left++;
				current_counts[idx]--;
				if (current_counts[idx] < target_counts[idx]) {
					mask ^= (unsigned long long) 1 << idx;
				}
			}
		}

		while (mask == ALL_GOOD && left < right) {
			if (right - left < best_indices.second - best_indices.first) {
				best_indices = make_pair(left, right);
			}
			int idx = ((int) s[left]) - 'A';
			left++;
			current_counts[idx]--;
			if (current_counts[idx] < target_counts[idx]) {
				mask ^= (unsigned long long) 1 << idx;
			}
		}

		if (best_indices.second == INT_MAX) {
			return "";
		}
		return s.substr(best_indices.first, best_indices.second - best_indices.first);

    }
};
