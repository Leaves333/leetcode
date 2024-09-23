#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
		bool visited[rooms.size()];
		memset(visited, false, sizeof(visited));

		queue<int> q;
		q.push(0);
		while (q.size() > 0) {
			int top = q.front();
			q.pop();
			visited[top] = true;
			for (int edge : rooms[top]) {
				if (!visited[edge]) {
					q.push(edge);
				}
			}
		}
		
		for (bool x : visited) {
			if (!x) {
				return false;
			}
		}
		return true;
    }
};
