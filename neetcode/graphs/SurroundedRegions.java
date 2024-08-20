// wow this is really awful code D:
class Solution {

	private boolean[][] visited;
	private boolean surrounded;

	public void solve(char[][] board) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				if (board[i][j] == 'O') {
					visited = new boolean[board.length][board[0].length];
					surrounded = true;
					dfs(board, i, j, false);

					if (surrounded) {
						visited = new boolean[board.length][board[0].length];
						dfs(board, i, j, true);
					}
				}
			}
		}
	}

	private void dfs(char[][] board, int x, int y, boolean modify) {

		if (x == 0 || y == 0 || x == board.length - 1 || y == board[x].length - 1) {
			surrounded = false;
		}

		visited[x][y] = true;
		if (modify) {
			board[x][y] = 'X';
		}

		int[][] adj = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int[] d : adj) {

			int newX = x + d[0];
			int newY = y + d[1];

			if (newX < 0 || newX >= board.length || newY < 0 || newY >= board[newX].length) {
				continue;
			}

			if (board[newX][newY] == 'O' && !visited[newX][newY]) {
				dfs(board, newX, newY, modify);
			}

		}

	}
}
