#include <bits/stdc++.h>
using namespace std;

/*Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		unordered_map<TreeNode*, pair<int, int>> map;
		dfs(root, p, q, map, 0);
		int max_depth = -1;
		TreeNode* ans = nullptr;
		for (auto pair : map) {
			if (pair.second.first == 3 && pair.second.second > max_depth) {
				max_depth = pair.second.second;
				ans = pair.first;
			}
		}
		return ans;
    }

	void dfs(TreeNode* root, TreeNode* p, TreeNode* q, unordered_map<TreeNode*, pair<int, int>> &map, int depth) {

		// base case
		if (root == p) {
			map[root] = make_pair(1, depth);
		}
		else if (root == q) {
			map[root] = make_pair(2, depth);
		}
		else if (map.count(root) > 0) {
			return;
		} else {
			map[root] = make_pair(0, depth);
		}

		if (root->left != nullptr) {
			if (map.count(root->left) == 0) {
				dfs(root->left, p, q, map, depth + 1);
			}
			map[root].first |= map[root->left].first;
		}

		if (root->right != nullptr) {
			if (map.count(root->right) == 0) {
				dfs(root->right, p, q, map, depth + 1);
			}
			map[root].first |= map[root->right].first;
		}

	}
};
