package main

func sumNumbers(root *TreeNode) int {
	var ret int
	sumNumbersHelper(root, 0, &ret)
	return ret
}

func sumNumbersHelper(root *TreeNode, curNum int, sum *int) {
	curNum *= 10
	curNum += root.Val
	if root.Left == nil && root.Right == nil {
		*sum += curNum
		return
	}

	if root.Left != nil {
		sumNumbersHelper(root.Left, curNum, sum)
	}
	if root.Right != nil {
		sumNumbersHelper(root.Right, curNum, sum)
	}
}
