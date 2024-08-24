import java.util.*;

class Solution {

	private HashMap<Integer, HashSet<Integer>> prereqs;
	private HashMap<Integer, HashSet<Integer>> fulfills;
	private boolean[] taken;
	private int[] order;
	private int index;

	public int[] findOrder(int numCourses, int[][] prerequisites) {

		taken = new boolean[numCourses];
		order = new int[numCourses];
		index = 0;
		prereqs = new HashMap<>();
		fulfills = new HashMap<>();

		for (int i = 0; i < numCourses; i++) {
			prereqs.put(i, new HashSet<>());
			fulfills.put(i, new HashSet<>());
		}

		for (int[] r : prerequisites) {
			prereqs.get(r[0]).add(r[1]);
			fulfills.get(r[1]).add(r[0]);
		}

		for (int i = 0; i < numCourses; i++) {
			dfs(i);
		}

		if (index == numCourses) {
			return order;
		}
		return new int[0];

	}

	private void dfs(int course) {

		for (int req : prereqs.get(course))
			if (!taken[req])
				return;

		if (taken[course])
			return;

		taken[course] = true;
		order[index] = course;
		index++;

		for (int x : fulfills.get(course)) {
			dfs(x);
		}

	}

}
