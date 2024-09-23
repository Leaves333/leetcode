#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:

	queue<int> queue;
    RecentCounter() {

    }
    
    int ping(int t) {
		queue.push(t);
		while (queue.front() < t - 3000) {
			queue.pop();
		}
		return queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
