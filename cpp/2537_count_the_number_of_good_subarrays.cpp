#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long calc_pairs(long long x) {
        return x * (x-1) / 2;
    }

    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long ans = 0;
        map<int, int> freq;

        long long pairs = 0;
        while (l < nums.size()) {

            while (pairs < k && r < nums.size()) {
                pairs -= calc_pairs(freq[nums[r]]);
                freq[nums[r]]++;
                pairs += calc_pairs(freq[nums[r]]);
                r++;
            }

            if (pairs >= k)
                ans += nums.size() - r + 1;

            pairs -= calc_pairs(freq[nums[l]]);
            freq[nums[l]]--;
            pairs += calc_pairs(freq[nums[l]]);
            l++;

        }
        return ans;
    }

};
