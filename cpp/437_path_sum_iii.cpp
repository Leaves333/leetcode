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

    int pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return 0;
		}
		int ans = 0;
		queue<TreeNode*> queue;
		queue.push(root);
		while (queue.size() > 0) {
			auto top = queue.front();
			queue.pop();
			ans += dfs(top, targetSum, 0);
			if (top->left != nullptr) {
				queue.push(top->left);
			}
			if (top->right != nullptr) {
				queue.push(top->right);
			}
		}
		return ans;
    }

	int dfs(TreeNode* root, long long targetSum, long long currentSum) {
		if (root == nullptr) {
			return 0;
		}
		
		currentSum += root->val;
		int ans = 0;
		if (currentSum == targetSum) {
			ans++;
		}
		ans += dfs(root->left, targetSum, currentSum);
		ans += dfs(root->right, targetSum, currentSum);

		return ans;
	}
};
