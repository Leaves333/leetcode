#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
		vector<int> indexes;
		vector<char> vowels;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				indexes.push_back(i);
				vowels.push_back(s[i]);
			}
		}
		for (int i = 0; i < vowels.size(); i++) {
			s[indexes[vowels.size() - i - 1]] = vowels[i];
		}
		return s;
    }
};
