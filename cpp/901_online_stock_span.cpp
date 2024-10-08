#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:

	stack<pair<int, int>> s; // price, span
    StockSpanner() {
    }
    
    int next(int price) {
		int ans = 1;
		while (s.size() > 0 && price >= s.top().first) {
			auto top = s.top();
			s.pop();
			ans += top.second;
		}
		s.push(make_pair(price, ans));
		return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
