class Solution {

	public boolean isValidBST(TreeNode root) {
		return validate(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
	}

	private boolean validate(TreeNode root, int left, int right) {
		if (root == null)
			return true;
		if (root.val <= left || root.val >= right)
			return false;
		return validate(root.left, left, root.val) && validate(root.right, root.val, right);
	}

}
