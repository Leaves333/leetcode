import java.util.*;

class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> list = new ArrayList<>();
		traverse(list, 0, root);
		return list;
	}

	private void traverse(List<List<Integer>> list, int depth, TreeNode root) {
		if (root == null)
			return;
		if (depth >= list.size())
			list.add(new ArrayList<>());
		list.get(depth).add(root.val);
		traverse(list, depth + 1, root.left);
		traverse(list, depth + 1, root.right);
	}
}
