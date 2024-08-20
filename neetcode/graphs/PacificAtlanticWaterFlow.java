import java.util.*;

class Solution {

	private boolean pacific;
	private boolean atlantic;
	private boolean[][] visited;

	public List<List<Integer>> pacificAtlantic(int[][] heights) {

		List<List<Integer>> ans = new ArrayList<>();

		for (int i = 0; i < heights.length; i++) {
			for (int j = 0; j < heights[i].length; j++) {
				visited = new boolean[heights.length][heights[0].length];
				pacific = false;
				atlantic = false;
				dfs(heights, i, j);
				if (pacific && atlantic) {
					List<Integer> curPos = new ArrayList<>();
					curPos.add(i);
					curPos.add(j);
					ans.add(curPos);
				}
			}
		}

		return ans;

	}

	private void dfs(int[][] heights, int x, int y) {

		if (visited[x][y])
			return;
		visited[x][y] = true;

		if (x == 0 || y == 0)
			pacific = true;
		if (x == heights.length - 1 || y == heights[x].length - 1)
			atlantic = true;

		int[][] adj = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int[] d : adj) {

			int newX = x + d[0];
			int newY = y + d[1];

			if (newX < 0 || newX >= heights.length || newY < 0 || newY >= heights[0].length)
				continue;

			if (heights[newX][newY] <= heights[x][y])
				dfs(heights, newX, newY);

		}

	}

}
