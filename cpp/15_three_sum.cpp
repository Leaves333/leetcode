#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip dupes

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {

                int cur = nums[i] + nums[left] + nums[right];

                if (cur > 0)
                    right--;
                else if (cur < 0)
                    left++;
                else {
                    ans.push_back(vector<int> ({nums[i], nums[left], nums[right]}));
                    right--;
                    while (nums[right] == nums[right + 1] && right > left)
                        right--; // skip dupes again
                }
                
            }
        }
        return ans;
    }
};