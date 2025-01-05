package main

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return make([]int, 0)
	}
	cur := []*TreeNode{root}
	ans := make([]int, 0)
	for true {
		ans = append(ans, cur[len(cur)-1].Val)
		nextLayer := make([]*TreeNode, 0)
		for _, node := range cur {
			if node.Left != nil {
				nextLayer = append(nextLayer, node.Left)
			}
			if node.Right != nil {
				nextLayer = append(nextLayer, node.Right)
			}
		}
		if len(nextLayer) > 0 {
			cur = nextLayer
		} else {
			break
		}
	}
	return ans
}
