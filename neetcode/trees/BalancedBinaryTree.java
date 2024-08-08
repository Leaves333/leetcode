class Solution {

	public boolean isBalanced(TreeNode root) {
		if (root == null)
			return true;
		if (!isBalanced(root.left) || !isBalanced(root.right))
			return false;
		if (Math.abs(maxDepth(root.left) - maxDepth(root.right)) > 1)
			return false;
		return true;
	}

	public int maxDepth(TreeNode node) {
		if (node == null)
			return 0;
		return 1 + Math.max(maxDepth(node.left), maxDepth(node.right));
	}

}
