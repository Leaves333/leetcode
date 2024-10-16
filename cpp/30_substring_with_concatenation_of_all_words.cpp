#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

		map<string, int> frequencies;
		int word_length = words[0].length();
		for (string word : words) {
			if (frequencies.count(word) == 0) {
				frequencies[word] = 0;
			}
			frequencies[word]++;
		}

		vector<int> ans;
		for (int offset = 0; offset < word_length; offset++) {
			map<string, int> substrings;
			int words_counted = 0;
			for (int index = offset; index < (int) s.length() - word_length + 1; index += word_length) {
				string substr = s.substr(index, word_length);
				if (substrings.count(substr) == 0) {
					substrings[substr] = 0;
				}
				substrings[substr]++;
				words_counted++;

				if (words_counted >= words.size()) {
					bool good = true;
					for (auto pair : substrings) {
						if (frequencies[pair.first] != substrings[pair.first]) {
							good = false;
							break;
						}
					}

					int old_index = index - (word_length * (words.size() - 1));
					if (good) {
						ans.push_back(old_index);
					}
					string oldest_substring = s.substr(old_index, word_length);
					substrings[oldest_substring]--;
				}
			}
		}

		return ans;
    }
};
