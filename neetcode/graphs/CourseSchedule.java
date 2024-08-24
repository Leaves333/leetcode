import java.util.*;

class Solution {

	private boolean[] finished;

	public boolean canFinish(int numCourses, int[][] prerequisites) {

		finished = new boolean[numCourses];
		HashMap<Integer, HashSet<Integer>> prereqs = new HashMap<>();
		HashMap<Integer, HashSet<Integer>> fulfills = new HashMap<>();
		for (int i = 0; i < numCourses; i++) {
			prereqs.put(i, new HashSet<>());
			fulfills.put(i, new HashSet<>());
		}

		for (int[] req : prerequisites) {
			prereqs.get(req[0]).add(req[1]);
			fulfills.get(req[1]).add(req[0]);
		}

		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < numCourses; i++) {
			if (prereqs.get(i).size() == 0) {
				stack.add(i);
			}
		}

		while (!stack.empty()) {

			int top = stack.pop();
			boolean canTakeCourse = true;

			for (int req : prereqs.get(top)) {
				if (!finished[req]) {
					canTakeCourse = false;
					break;
				}
			}
			if (!canTakeCourse)
				continue;

			finished[top] = true;
			for (int x : fulfills.get(top)) {
				stack.add(x);
			}

		}

		for (int i = 0; i < numCourses; i++)
			if (!finished[i])
				return false;
		return true;

	}

}
