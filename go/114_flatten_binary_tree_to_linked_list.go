package main

func flatten(root *TreeNode) {

	if root == nil {
		return
	}

	stack := make([]*TreeNode, 0)
	stack = append(stack, root)

	for len(stack) > 0 {
		top := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if top.Right != nil {
			stack = append(stack, top.Right)
		}
		if top.Left != nil {
			stack = append(stack, top.Left)
		}

		top.Left = nil
		if len(stack) > 0 {
			top.Right = stack[len(stack)-1]
		} else {
			top.Right = nil
		}
	}

}
