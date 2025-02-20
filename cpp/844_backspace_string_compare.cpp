#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first;
        stack<char> second;
        for (char c : s) {
            if (c == '#') {
                if (first.size() > 0)
                    first.pop();
            } else {
                first.push(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (second.size() > 0)
                    second.pop();
            } else {
                second.push(c);
            }
        }
        return first == second;
    }
};
