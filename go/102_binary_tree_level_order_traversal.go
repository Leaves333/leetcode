package main

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return make([][]int, 0)
	}
	cur := []*TreeNode{root}
	ans := make([][]int, 0)
	for true {
		nextLevel := make([]*TreeNode, 0)
		curLevel := make([]int, 0)
		for _, node := range cur {
			curLevel = append(curLevel, node.Val)
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}
		ans = append(ans, curLevel)
		if len(nextLevel) > 0 {
			cur = nextLevel
		} else {
			break
		}
	}
	return ans
}
