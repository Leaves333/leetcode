package main

func countNodesHelper(root *TreeNode, x int, maxDepth int) bool {
	for i := maxDepth - 1; i >= 0; i-- {
		if (x & (1 << i)) > 0 {
			root = root.Right
		} else {
			root = root.Left
		}
		if root == nil {
			return false
		}
	}
	return true
}

func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}

	depth := 0
	cur := root
	for cur.Left != nil {
		depth++
		cur = cur.Left
	}

	nodes := 0
	curLayer := 1
	for _ = range depth {
		nodes += curLayer
		curLayer *= 2
	}

	low := 0
	high := curLayer - 1
	for low < high {
		mid := low + (high-low+1)/2
		if countNodesHelper(root, mid, depth) {
			low = mid
		} else {
			high = mid - 1
		}
	}

	return nodes + low + 1

}
