#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        string longest = "";
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                map<char, int> freq;
                for (int k = i; k <= j; k++) {
                    freq[s[k]]++;
                }

                bool valid = true;
                for (const auto &[key, value] : freq) {
                    cout << "checking " << key << endl;
                    if (value < 1)
                        continue;
                    if (key < 'a' && freq['a' + (key - 'A')] < 1) {
                        valid = false;
                        break;
                    } else if (key >= 'a' && freq['A' + (key - 'a')] < 1) {
                        valid = false;
                        break;
                    }

                }

                if (valid && j-i+1 > longest.length())
                    longest = s.substr(i, j-i+1);
            }
        }
        return longest;
    }
};
