import java.util.*;

class Solution {
	public List<Integer> rightSideView(TreeNode root) {
		List<Integer> list = new ArrayList<>();
		solve(list, 0, root);
		return list;
	}

	private void solve(List<Integer> list, int depth, TreeNode node) {
		if (node == null)
			return;
		if (depth >= list.size())
			list.add(node.val);
		solve(list, depth + 1, node.right);
		solve(list, depth + 1, node.left);
	}
}
