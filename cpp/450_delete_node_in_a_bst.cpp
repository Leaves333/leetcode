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
    TreeNode* deleteNode(TreeNode* root, int key) {

		if (root == nullptr) {
			return nullptr;
		}

		if (root->val > key) {
			root->left = deleteNode(root->left, key);
		} else if (root->val < key) {
			root->right = deleteNode(root->right, key);
		} else {
			
			// no children
			if (root->left == nullptr && root->right == nullptr) {
				return nullptr;
			}

			// one child
			if (root->left == nullptr) {
				return root->right;
			}
			if (root->right == nullptr) {
				return root->left;
			}

			TreeNode* tmp = root->right;
			while (tmp->left != nullptr) {
				tmp = tmp->left;
			}
			root->val = tmp->val;
			root->right = deleteNode(root->right, tmp->val);
			
		} 

		return root;

    }
};
