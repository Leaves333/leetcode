package main

func buildTree(preorder []int, inorder []int) *TreeNode {

	if len(preorder) == 0 {
		return nil
	}

	// preorder: mid, left, right
	// inorder: left, right, mid

	root := &TreeNode{}
	idx := -1
	for i := range len(inorder) {
		if inorder[i] == preorder[0] {
			idx = i
			break
		}
	}

	root.Val = preorder[0]
	root.Left = buildTree(preorder[1:idx+1], inorder[:idx])
	root.Right = buildTree(preorder[idx+1:], inorder[idx+1:])

	return root

}
