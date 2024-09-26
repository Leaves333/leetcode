#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:

	int i;
	multiset<int> m;
    SmallestInfiniteSet() {
		i = 1;
		m.insert(i);
    }
    
    int popSmallest() {
		int x = *m.begin();
		m.erase(m.begin());
		if (m.size() == 0) {
			i++;
			m.insert(i);
		}
		return x;
    }
    
    void addBack(int num) {
		if (num >= i || m.count(num) > 0) {
			return;
		}
		m.insert(num);
    }

};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
