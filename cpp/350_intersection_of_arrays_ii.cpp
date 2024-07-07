#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        multiset<int> a (nums1.begin(), nums1.end());
        multiset<int> b (nums2.begin(), nums2.end());

        vector<int> ans;
        for (int x : a) {
            auto it = b.find(x);
            if (it != b.end()) {
                ans.push_back(*it);
                b.erase(it);
            }
        }

        return ans;
        
    }
};