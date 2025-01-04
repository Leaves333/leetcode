package main

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	dp := make(map[*TreeNode]int)
	lowestCommonAncestorDFS(root, p, q, dp)
	for true {
		if dp[root.Left] == 3 {
			root = root.Left
		} else if dp[root.Right] == 3 {
			root = root.Right
		} else {
			break
		}
	}
	return root
}

func lowestCommonAncestorDFS(root, p, q *TreeNode, dp map[*TreeNode]int) {

	if root == nil {
		return
	} else if root == p {
		dp[root] |= 1
	} else if root == q {
		dp[root] |= 2
	}

	_, ok := dp[root.Left]
	if !ok {
		lowestCommonAncestorDFS(root.Left, p, q, dp)
	}
	_, ok = dp[root.Right]
	if !ok {
		lowestCommonAncestorDFS(root.Right, p, q, dp)
	}
	dp[root] |= dp[root.Left] | dp[root.Right]
}
