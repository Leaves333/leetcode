import java.util.Stack;

class Solution {
	public int kthSmallest(TreeNode root, int k) {
		Stack<TreeNode> stack = new Stack<>();
		TreeNode cur = root;

		while (cur != null || !stack.isEmpty()) {

			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}

			cur = stack.pop();
			k--;
			if (k == 0) {
				return cur.val;
			}
			cur = cur.right;
		}
		return -1;
	}
}
