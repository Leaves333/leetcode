import java.util.*;

class Solution {

	public int ladderLength(String beginWord, String endWord, List<String> wordList) {

		// build the graph
		// dijkstra to find shortest path

		HashMap<String, Integer> distance = new HashMap<>();
		HashMap<String, List<String>> edges = new HashMap<>();

		for (String word : wordList) {
			distance.put(word, Integer.MAX_VALUE);
			edges.put(word, new ArrayList<>());
		}
		distance.put(beginWord, 0);
		edges.put(beginWord, new ArrayList<>());

		if (!distance.containsKey(endWord)) {
			return 0;
		}

		for (int i = 0; i < wordList.size(); i++) {
			for (int j = i + 1; j < wordList.size(); j++) {
				if (adjacent(wordList.get(i), wordList.get(j))) {
					edges.get(wordList.get(i)).add(wordList.get(j));
					edges.get(wordList.get(j)).add(wordList.get(i));
				}
			}
		}
		for (int i = 0; i < wordList.size(); i++) {
			if (adjacent(wordList.get(i), beginWord)) {
				edges.get(beginWord).add(wordList.get(i));
				edges.get(wordList.get(i)).add(beginWord);
			}
		}

		Queue<String> queue = new LinkedList<>();
		queue.add(beginWord);

		while (!queue.isEmpty()) {
			String cur = queue.poll();
			for (String dest : edges.get(cur)) {
				if (distance.get(dest) > distance.get(cur) + 1) {
					distance.put(dest, distance.get(cur) + 1);
					queue.add(dest);
				}
			}
		}

		if (distance.get(endWord) == Integer.MAX_VALUE) {
			return 0;
		}
		return distance.get(endWord) + 1;

	}

	private boolean adjacent(String a, String b) {
		int count = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) != b.charAt(i)) {
				count++;
				if (count > 1) {
					return false;
				}
			}
		}
		return count == 1;
	}

}
