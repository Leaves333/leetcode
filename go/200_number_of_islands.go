package main

func numIslands(grid [][]byte) int {
	ans := 0
	visited := make([][]bool, len(grid))
	for i := range len(grid) {
		visited[i] = make([]bool, len(grid[0]))
	}
	for i, _ := range grid {
		for j, _ := range grid[0] {
			if !visited[i][j] && grid[i][j] == '1' {
				numIslandsDFS(i, j, grid, visited)
				ans++
			}
		}
	}
	return ans
}

func numIslandsDFS(x, y int, grid [][]byte, visited [][]bool) {
	visited[x][y] = true
	changes := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	for _, c := range changes {
		newX := x + c[0]
		newY := y + c[1]
		if newX < 0 || newX >= len(grid) || newY < 0 || newY >= len(grid[0]) {
			continue
		}
		if visited[newX][newY] {
			continue
		}
		if grid[newX][newY] == '1' {
			numIslandsDFS(newX, newY, grid, visited)
		}
	}
}
