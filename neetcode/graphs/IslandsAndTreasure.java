class Solution {

	public void islandsAndTreasure(int[][] grid) {
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				if (grid[i][j] == 0) {
					dfs(grid, i, j);
				}
			}
		}
	}

	private void dfs(int[][] grid, int x, int y) {

		int[][] adjacent = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int i = 0; i < 4; i++) {

			int newX = x + adjacent[i][0];
			int newY = y + adjacent[i][1];

			if (!(newX >= 0 && newX < grid.length && newY >= 0 && newY < grid[newX].length))
				continue;

			if (grid[x][y] + 1 < grid[newX][newY]) {
				grid[newX][newY] = grid[x][y] + 1;
				dfs(grid, newX, newY);
			}

		}

	}

}
