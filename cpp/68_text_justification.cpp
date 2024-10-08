#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;

		int current_width = 0;
 		vector<string> cur_line;
		for (string word : words) {
			if (current_width + word.length() + cur_line.size() > maxWidth) {

				int missing_width = maxWidth - current_width;
				int num_gaps = max((int) cur_line.size() - 1, 1);

				int spaces_per_gap = missing_width / num_gaps;
				int remainder = missing_width % num_gaps;
				
				string line;
				for (int i = 0; i < remainder; i++) {
					line += cur_line[i];
					for (int j = 0; j < spaces_per_gap; j++) {
						line += " ";
					}
					line += " ";
				}

				for (int i = remainder; i < cur_line.size() - 1; i++) {
					line += cur_line[i];
					for (int j = 0; j < spaces_per_gap; j++) {
						line += " ";
					}
				}
				line += cur_line[cur_line.size() - 1];
				while (line.length() < maxWidth) {
					line += " ";
				}
				ans.push_back(line);

				current_width = 0;
				cur_line.erase(cur_line.begin(), cur_line.end());
			}

			current_width += word.length();
			cur_line.push_back(word);
		}

		if (cur_line.size() != 0) {
			string line;
			for (int i = 0; i < cur_line.size() - 1; i++) {
				line += cur_line[i] + " ";
			}
			line += cur_line[cur_line.size() - 1];
			while (line.length() < maxWidth) {
				line += " ";
			}
			ans.push_back(line);
		}

		return ans;
    }
};
