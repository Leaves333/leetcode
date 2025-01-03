package main

import "math"

func maxPathSum(root *TreeNode) int {
	ans := math.MinInt
	maxPath(root, &ans)
	return ans
}

func maxPath(root *TreeNode, ans *int) int {
	if root == nil {
		return 0
	}

	lmax := max(0, maxPath(root.Left, ans))
	rmax := max(0, maxPath(root.Right, ans))
	*ans = max(*ans, root.Val+lmax+rmax)
	return root.Val + max(lmax, rmax)
}
