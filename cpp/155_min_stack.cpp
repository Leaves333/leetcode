#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

	stack<pair<int, int>> s; // val, min val
    MinStack() {
		s = stack<pair<int, int>>();
    }
    
    void push(int val) {
		if (s.size() > 0) {
			s.push(make_pair(val, min(s.top().second, val)));
		} else {
			s.push(make_pair(val, val));
		}
    }
    
    void pop() {
		s.pop();
    }
    
    int top() {
		return s.top().first;
    }
    
    int getMin() {
		return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
