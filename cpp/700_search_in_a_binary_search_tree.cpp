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
    TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode* cur = root;
		while (cur != nullptr) {
			if (cur->val == val) {
				return cur;
			} else if (cur->val > val) {
				cur = cur->left;
			} else {
				cur = cur->right;
			}
		}
		return nullptr;
    }
};
