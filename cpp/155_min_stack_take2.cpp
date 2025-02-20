#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {
        s = stack<pair<int, int>>();
    }
    
    void push(int val) {
        int new_min = val;
        if (!s.empty())
            new_min = min(new_min, s.top().second);
        s.push(make_pair(val, new_min));
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
