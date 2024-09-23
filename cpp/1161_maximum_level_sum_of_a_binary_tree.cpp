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
    int maxLevelSum(TreeNode* root) {

		int max_depth = 0, max_sum = INT_MIN;
		int depth = 1;
		queue<TreeNode*> q;
		q.push(root);

		while (q.size() > 0) {

			int size = q.size();
			int sum = 0;
			for (int i = 0; i < size; i++) {
				TreeNode* cur = q.front();
				q.pop();
				sum += cur->val;
				
				if (cur->left != nullptr) {
					q.push(cur->left);
				}
				if (cur->right != nullptr) {
					q.push(cur->right);
				}
			}

			if (sum > max_sum) {
				max_sum = sum;
				max_depth = depth;
			}
			depth++;

		}

		return max_depth;
		
    }
};
