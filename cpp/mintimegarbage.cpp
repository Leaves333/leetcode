#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last_glass = 0, last_paper = 0, last_metal = 0;
        int total_garbage = 0;
        for (int i = 0; i < garbage.size(); i++) {
            bool found_glass = false, found_paper = false, found_metal = false;
            total_garbage += garbage[i].length();
            for (char c : garbage[i]) {
                if (c == 'G') {
                    found_glass = true;
                } else if (c == 'P') {
                    found_paper = true;
                } else if (c == 'M') {
                    found_metal = true;
                }
            }
            if (found_glass)
                last_glass = i;
            if (found_paper)
                last_paper = i;
            if (found_metal)
                last_metal = i;
        }

        int total = total_garbage;
        vector<int> psum(garbage.size());
        for (int i = 0; i < travel.size(); i++) {
            psum[i + 1] = psum[i] + travel[i];
        }
        total += psum[last_glass];
        total += psum[last_paper];
        total += psum[last_metal];
        return total;
    }
};
