#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	TrieNode* arr[26];
	bool isWord;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

		// create trie
		TrieNode *root = new TrieNode();
		memset(root->arr, 0, sizeof(root->arr));
		root->isWord = false;
		
		for (string word : products) {
			TrieNode *cur = root;
			for (char c : word) {
				if (cur->arr[c - 'a'] == 0) {
					cur->arr[c - 'a'] = new TrieNode();
					cur = cur->arr[c - 'a'];
					memset(cur->arr, 0, sizeof(cur->arr));
					cur->isWord = false;
				} else {
					cur = cur->arr[c - 'a'];
				}
			}
			cur->isWord = true;
		}

		vector<vector<string>> ans;
		string prefix = "";
		TrieNode *cur = root;
		bool good = true;

		for (char c : searchWord) {
			vector<string> v;
			if (good && cur->arr[c - 'a'] != 0) {
				cur = cur->arr[c - 'a'];
				prefix += c;
				dfs(cur, &v, &prefix);
			} else {
				good = false;
			}
			ans.push_back(v);
		}
		return ans;
    }

private:
	void dfs(TrieNode* root, vector<string> *ans, string *cur) {
		if (root->isWord) {
			ans->push_back(*cur);
		}
		if (ans->size() >= 3) {
			return;
		}

		for (char c = 'a'; c <= 'z'; c++) {
			if (root->arr[c - 'a'] != 0) {
				cur += c;
				dfs(root->arr[c - 'a'], ans, cur);
				cur->pop_back();
			}
		}
	}
};
