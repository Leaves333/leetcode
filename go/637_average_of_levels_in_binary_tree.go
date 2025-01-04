package main

func averageOfLevels(root *TreeNode) []float64 {
	ans := make([]float64, 0)
	cur := []*TreeNode{root}
	for true {
		nextLevel := make([]*TreeNode, 0)
		sum := 0.0
		for _, node := range cur {
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
			sum += float64(node.Val)
		}
		ans = append(ans, sum/float64(len(cur)))
		if len(nextLevel) > 0 {
			cur = nextLevel
		} else {
			break
		}
	}
	return ans
}
