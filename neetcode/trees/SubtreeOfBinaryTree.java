class Solution {
	public boolean isSubtree(TreeNode root, TreeNode subRoot) {
		if (isSameTree(root, subRoot))
			return true;
		if (root != null)
			return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
		return false;
	}

	private boolean isSameTree(TreeNode a, TreeNode b) {
		if (a == null && b == null)
			return true;
		if (a != null && b != null && a.val == b.val)
			return isSameTree(a.left, b.left) && isSameTree(a.right, b.right);
		return false;
	}
}
