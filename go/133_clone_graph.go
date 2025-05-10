package main

type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	m := make(map[*Node]*Node, 0)
	stack := []*Node{node}
	for len(stack) > 0 {
		top := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		val, ok := m[top]
		if !ok {
			m[top] = &Node{top.Val, make([]*Node, 0)}
			val = m[top]
		}

	}

	return m[node]
}
