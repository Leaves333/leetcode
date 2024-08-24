import java.util.*;

class Solution {

	private boolean[] visited;
	private HashMap<Integer, List<Integer>> adj;

	public boolean validTree(int n, int[][] edges) {

		if (edges.length != n - 1)
			return false;

		visited = new boolean[n];
		adj = new HashMap<>();
		for (int i = 0; i < n; i++) {
			adj.put(i, new ArrayList<>());
		}

		for (int[] x : edges) {
			adj.get(x[0]).add(x[1]);
			adj.get(x[1]).add(x[0]);
		}

		dfs(0);
		for (boolean x : visited)
			if (!x)
				return false;
		return true;

	}

	private void dfs(int x) {

		if (visited[x])
			return;

		visited[x] = true;
		for (int dest : adj.get(x)) {
			dfs(dest);
		}

	}

}
