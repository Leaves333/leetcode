package main

func buildTree(inorder []int, postorder []int) *TreeNode {

	if len(postorder) == 0 {
		return nil
	}
	if len(postorder) == 1 {
		return &TreeNode{Val: postorder[0]}
	}

	idx := -1
	for i := range len(inorder) {
		if inorder[i] == postorder[len(postorder)-1] {
			idx = i
			break
		}
	}

	cur := &TreeNode{}
	cur.Val = postorder[len(postorder)-1]
	cur.Left = buildTree(inorder[:idx], postorder[:idx])
	cur.Right = buildTree(inorder[idx+1:], postorder[idx:len(postorder)-1])
	return cur

}
