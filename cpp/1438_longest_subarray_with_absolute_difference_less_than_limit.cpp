#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int left = 0, right = 0, ans = 0;
        multiset<int> cur;
        cur.insert(nums[0]);
        

        while (right < nums.size() - 1) {
            if (*(--cur.end()) - *cur.begin() <= limit) {
                ans = max(ans, right - left + 1);
                right++;
                cur.insert(nums[right]);
            }
            else {
                cur.erase(cur.find(nums[left]));
                left++;
            }
        }

        if (*(--cur.end()) - *cur.begin() <= limit) {
            ans = max(ans, right - left + 1);
        }
        return ans;

    }
};