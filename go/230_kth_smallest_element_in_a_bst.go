package main

func kthSmallest(root *TreeNode, k int) int {
	cur := root
	stack := make([]*TreeNode, 0)
	for cur.Left != nil {
		stack = append(stack, cur)
		cur = cur.Left
	}

	for _ = range k - 1 {

		// go right, then as left as possible
		if cur.Right != nil {
			stack = append(stack, cur)
			cur = cur.Right
			for cur.Left != nil {
				stack = append(stack, cur)
				cur = cur.Left
			}
			continue
		}

		// go up
		for true {
			parent := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if parent.Right == cur {
				cur = parent
				continue
			}
			cur = parent
			break
		}

	}
	return cur.Val
}
