#include <bits/stdc++.h>
using namespace std;

/*Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
		int ans = 0;
		if (root->left != nullptr) {
			ans = max(ans, dfs(root->left, 1, true));
		}
		if (root->right != nullptr) {
			ans = max(ans, dfs(root->right, 1, false));
		}
		return ans;
    }

	int dfs(TreeNode* root, int currentChain, bool wentLeft) {
		int ans = currentChain;
		if (root->left != nullptr) {
			if (!wentLeft) {
				ans = max(ans, dfs(root->left, currentChain + 1, true));
			} else {
				ans = max(ans, dfs(root->left, 1, true));
			}
		}
		if (root->right != nullptr) {
			if (wentLeft) {
				ans = max(ans, dfs(root->right, currentChain + 1, false));
			} else {
				ans = max(ans, dfs(root->right, 1, false));
			}
		}
		return ans;
	}
};
