package main

import "math"

func isValidBST(root *TreeNode) bool {
	return isValidBSTHelper(root, math.MinInt, math.MaxInt)
}

func isValidBSTHelper(root *TreeNode, l, r int) bool {
	if root == nil {
		return true
	}
	if root.Val <= l || root.Val >= r {
		return false
	}
	return isValidBSTHelper(root.Left, l, root.Val) && isValidBSTHelper(root.Right, root.Val, r)
}
