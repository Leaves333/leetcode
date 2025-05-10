package main

// type Node struct {
// 	Val   int
// 	Left  *Node
// 	Right *Node
// 	Next  *Node
// }

func connect(root *Node) *Node {

	if root == nil {
		return root
	}

	queue := make([]*Node, 0)
	queue = append(queue, root)
	next_level := make([]*Node, 0)

	for {
		for len(queue) > 0 {
			top := queue[0]
			queue = queue[1:]
			if len(queue) > 0 {
				top.Next = queue[0]
			} else {
				top.Next = nil
			}

			if top.Left != nil {
				next_level = append(next_level, top.Left)
			}
			if top.Right != nil {
				next_level = append(next_level, top.Right)
			}
		}

		if len(next_level) == 0 {
			break
		} else {
			queue = next_level
			next_level = make([]*Node, 0)
		}
	}

	return root

}
