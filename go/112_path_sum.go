package main

func hasPathSum(root *TreeNode, targetSum int) bool {
	return pathSumHelper(root, 0, targetSum)
}

func pathSumHelper(root *TreeNode, curSum int, targetSum int) bool {

	if root == nil {
		return false
	}

	curSum += root.Val
	if curSum == targetSum && root.Left == nil && root.Right == nil {
		return true
	}

	return pathSumHelper(root.Left, curSum, targetSum) || pathSumHelper(root.Right, curSum, targetSum)

}
