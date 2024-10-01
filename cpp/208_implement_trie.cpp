#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> map;
	bool isWord;
};

class Trie {
public:

	TrieNode *root;

    Trie() {
		root = new TrieNode();
		(*root).isWord = false;
    }
    
    void insert(string word) {
		TrieNode *cur = root;
		for (char c : word) {
			if (cur->map.count(c) > 0) {
				cur = cur->map[c];
			} else {
				cur->map[c] = new TrieNode();
				cur = cur->map[c];
				cur->isWord = false;
			}
		}
		cur->isWord = true;
    }
    
    bool search(string word) {
		TrieNode *cur = root;
		for (char c : word) {
			if (cur->map.count(c) > 0) {
				cur = cur->map[c];
			} else {
				return false;
			}
		}
		return cur->isWord;
    }
    
    bool startsWith(string prefix) {
		TrieNode *cur = root;
		for (char c : prefix) {
			if (cur->map.count(c) > 0) {
				cur = cur->map[c];
			} else {
				return false;
			}
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
