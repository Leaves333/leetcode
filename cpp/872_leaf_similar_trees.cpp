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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> first;
		vector<int> second;
		helper(root1, first);
		helper(root2, second);
		return first == second;
    }

	void helper(TreeNode* cur, vector<int> &v) {
		if (cur == nullptr) {
			return;
		}
		if (cur->left == nullptr && cur->right == nullptr) {
			v.push_back(cur->val);
		}
		helper(cur->left, v);
		helper(cur->right, v);
	}
};
