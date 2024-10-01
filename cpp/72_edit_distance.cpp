#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int dp[word1.length() + 1][word2.length() + 1];
		for (int i = 0; i < word2.length() + 1; i++) {
			dp[0][i] = i;
		}
		for (int i = 0; i < word1.length() + 1; i++) {
			dp[i][0] = i;
		}

		for (int i = 0; i < word1.length(); i++) {
			for (int j = 0; j < word2.length(); j++) {
				if (word1[i] == word2[j]) {
					dp[i + 1][j + 1] = dp[i][j];
				} else {
					int diagonal = dp[i][j] + 1;
					int left = dp[i + 1][j] + 1;
					int top = dp[i][j + 1] + 1; 
					dp[i + 1][j + 1] = min(diagonal, min(left, top));
				}
			}
		}

		return dp[word1.length()][word2.length()];
    }
};
