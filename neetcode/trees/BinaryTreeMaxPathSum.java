class Solution {

	public int maxPathSum(TreeNode root) {

		if (root == null) {
			return Integer.MIN_VALUE;
		}

		int maxSum = Math.max(0, maxPath(root.left)) + Math.max(0, maxPath(root.right)) + root.val;
		maxSum = Math.max(maxPathSum(root.left), maxSum);
		maxSum = Math.max(maxPathSum(root.right), maxSum);

		return maxSum;
	}

	private int maxPath(TreeNode root) {
		return maxPath(root, 0);
	}

	private int maxPath(TreeNode root, int cur) {

		if (root == null) {
			return cur;
		}

		int maxVal = cur + root.val;
		maxVal = Math.max(maxPath(root.left, cur + root.val), maxVal);
		maxVal = Math.max(maxPath(root.right, cur + root.val), maxVal);

		return maxVal;
	}

}
