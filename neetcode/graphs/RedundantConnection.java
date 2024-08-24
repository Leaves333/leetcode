class Solution {

	int[] parent;
	int[] rank;

	public int[] findRedundantConnection(int[][] edges) {

		// ok i have bad intution
		// add edges one by one, first edge that creates a cycle is bad

		parent = new int[edges.length];
		rank = new int[edges.length];
		for (int i = 0; i < edges.length; i++) {
			parent[i] = i;
			rank[i] = 1;
		}

		for (int[] edge : edges) {
			boolean status = merge(edge[0] - 1, edge[1] - 1);
			if (!status) {
				return edge;
			}
		}

		return new int[2];

	}

	private int parent(int x) {
		if (rank[x] <= 0) {
			return parent(parent[x]);
		}
		return parent[x];
	}

	private boolean merge(int a, int b) {

		int aParent = parent(a);
		int bParent = parent(b);

		if (aParent == bParent) {
			return false;
		}

		if (rank[aParent] < rank[bParent]) {
			parent[bParent] = parent[aParent];
			rank[aParent] += rank[bParent];
			rank[bParent] = 0;
		} else {
			parent[aParent] = parent[bParent];
			rank[bParent] += rank[aParent];
			rank[aParent] = 0;
		}

		return true;

	}

}
