#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	const map<char, string> kDigits = {
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"},
	};

    vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits.length() == 0) {
			return ans;
		}

		string cur;
		vector<string> suffixes = letterCombinations(digits.substr(1, digits.length() - 1));
		for (char c : kDigits.at(digits[0])) {
			cur += c;
			if (suffixes.size() == 0) {
				ans.push_back(cur);
			}
			for (string s : suffixes) {
				ans.push_back(cur + s);
			}
			cur.pop_back();
		}
		
		return ans;
    }

};
