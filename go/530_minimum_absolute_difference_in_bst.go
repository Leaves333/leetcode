package main

func getMinimumDifference(root *TreeNode) int {
	return getMinimumDifferenceHelper(root, -1000000, 1000000)
}

func getMinimumDifferenceHelper(root *TreeNode, l, r int) int {
	ret := min(r-root.Val, root.Val-l)
	if root.Left != nil {
		ret = min(ret, getMinimumDifferenceHelper(root.Left, l, root.Val))
	}
	if root.Right != nil {
		ret = min(ret, getMinimumDifferenceHelper(root.Right, root.Val, r))
	}
	return ret
}
