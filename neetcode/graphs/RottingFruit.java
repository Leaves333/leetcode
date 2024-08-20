class Solution {
	public int orangesRotting(int[][] grid) {

		int[][] time = new int[grid.length][grid[0].length];

		for (int i = 0; i < grid.length; i++)
			for (int j = 0; j < grid[i].length; j++)
				time[i][j] = Integer.MAX_VALUE;

		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				if (grid[i][j] == 2) {
					time[i][j] = 0;
					dfs(grid, time, i, j);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < grid.length; i++)
			for (int j = 0; j < grid[i].length; j++)
				if (grid[i][j] != 0)
					ans = Math.max(ans, time[i][j]);

		if (ans == Integer.MAX_VALUE)
			return -1;
		return ans;

	}

	private void dfs(int[][] grid, int[][] time, int x, int y) {

		int[][] adj = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int[] arr : adj) {

			int newX = x + arr[0];
			int newY = y + arr[1];

			if (newX < 0 || newX >= grid.length || newY < 0 || newY >= grid[newX].length)
				continue;

			if (grid[newX][newY] == 0)
				continue;

			if (time[x][y] + 1 < time[newX][newY]) {
				time[newX][newY] = time[x][y] + 1;
				dfs(grid, time, newX, newY);
			}

		}
	}
}
