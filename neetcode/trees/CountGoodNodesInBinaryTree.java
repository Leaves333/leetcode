class Solution {

	private int ans;

	public int goodNodes(TreeNode root) {
		ans = 0;
		solve(root.val, root);
		return ans;
	}

	public void solve(int max, TreeNode node) {
		if (node == null)
			return;
		if (node.val >= max)
			ans += 1;
		max = Math.max(max, node.val);
		solve(max, node.left);
		solve(max, node.right);
	}

}
