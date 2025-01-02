package main

func isSymmetric(root *TreeNode) bool {
	return compare(root.Left, root.Right)
}

func compare(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	} else if left == nil || right == nil {
		return false
	} else if left.Val != right.Val {
		return false
	}
	return compare(left.Right, right.Left) && compare(left.Left, right.Right)
}
