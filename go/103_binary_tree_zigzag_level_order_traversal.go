package main

import "slices"

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return make([][]int, 0)
	}
	ans := make([][]int, 0)
	cur := []*TreeNode{root}
	reverse := false
	for true {
		nextLevel := make([]*TreeNode, 0)
		curLayer := make([]int, 0)
		for _, node := range cur {
			curLayer = append(curLayer, node.Val)
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}
		if reverse {
			slices.Reverse(curLayer)
		}
		reverse = !reverse
		ans = append(ans, curLayer)
		if len(nextLevel) > 0 {
			cur = nextLevel
		} else {
			break
		}
	}
	return ans
}
