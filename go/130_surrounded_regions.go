package main

func solve(board [][]byte) {
	visited := make([][]bool, len(board))
	staysO := make([][]bool, len(board))
	for i := range len(board) {
		visited[i] = make([]bool, len(board[0]))
		staysO[i] = make([]bool, len(board[0]))
	}

	for i := range len(board) {
		surroundedRegionsDFS(i, 0, board, visited, staysO)
		surroundedRegionsDFS(i, len(board[0])-1, board, visited, staysO)
	}
	for j := range len(board[0]) {
		surroundedRegionsDFS(0, j, board, visited, staysO)
		surroundedRegionsDFS(len(board)-1, j, board, visited, staysO)
	}

	for i := range len(board) {
		for j := range len(board[0]) {
			if !staysO[i][j] {
				board[i][j] = 'X'
			}
		}
	}
}

func surroundedRegionsDFS(x, y int, board [][]byte, visited, staysO [][]bool) {
	if visited[x][y] || board[x][y] == 'X' {
		return
	}
	visited[x][y] = true
	staysO[x][y] = true

	changes := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	for _, c := range changes {
		newX := x + c[0]
		newY := y + c[1]
		if newX < 0 || newX >= len(board) || newY < 0 || newY >= len(board[0]) {
			continue
		}
		surroundedRegionsDFS(newX, newY, board, visited, staysO)
	}
}
