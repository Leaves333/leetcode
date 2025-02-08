#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            if (people[right] + people[left] <= limit) {
                ans++;
                right--;
                left++;
            } else {
                ans++;
                right--;
            }
        }
        return ans;
    }
};
