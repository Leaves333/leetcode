import java.util.*;

class Solution {

	private HashMap<Integer, List<Integer>> adj;
	private boolean[] visited;

	public int countComponents(int n, int[][] edges) {

		adj = new HashMap<>();
		visited = new boolean[n];

		for (int i = 0; i < n; i++) {
			adj.put(i, new ArrayList<>());
		}

		for (int[] x : edges) {
			adj.get(x[0]).add(x[1]);
			adj.get(x[1]).add(x[0]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(i);
				ans++;
			}
		}

		return ans;

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
