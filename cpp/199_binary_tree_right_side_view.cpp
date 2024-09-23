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
    vector<int> rightSideView(TreeNode* root) {

		vector<int> res;
		if (root == nullptr) {
			return res;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (q.size() > 0) {

			int size = q.size();
			int i = 0;

			while (i < size) {

				TreeNode* cur = q.front();
				q.pop();
				i++;
				if (i == size) {
					res.push_back(cur->val);
				}

				if (cur->left != nullptr) {
					q.push(cur->left);
				}
				if (cur->right != nullptr) {
					q.push(cur->right);
				}

			}
		}

		return res;
    }
};
