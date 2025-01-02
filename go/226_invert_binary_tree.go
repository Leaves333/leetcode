package main

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	invertTree(root.Left)
	invertTree(root.Right)
	tmp := root.Left
	root.Left = root.Right
	root.Right = tmp
	return root
}
