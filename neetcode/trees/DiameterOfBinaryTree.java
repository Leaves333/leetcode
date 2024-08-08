class Solution {

	public int diameterOfBinaryTree(TreeNode root) {
		if (root == null)
			return 0;
		int ans = maxDepth(root.left) + maxDepth(root.right);
		ans = Math.max(ans, diameterOfBinaryTree(root.left));
		return Math.max(ans, diameterOfBinaryTree(root.right));
	}

	private int maxDepth(TreeNode root) {
		if (root == null)
			return 0;
		return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
	}

}
