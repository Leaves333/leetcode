#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long count_zeros(int k) {
        long long ans = 0;
        while (k > 0) {
            ans += k;
            k /= 5;
        }
        return ans;
    }

    int preimageSizeFZF(int k) {
        long long low = 0, high = k;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (count_zeros(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }
        return count_zeros(low) == k ? 5 : 0;
    }
};
