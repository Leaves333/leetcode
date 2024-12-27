#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
		a %= 1337;
		int ans = 1;
		int last_digit = a;
		for (int i = b.size() - 1; i >= 0; i--) {
			int val = 1;
			for (int j = 0; j < b[i]; j++) {
				val *= last_digit;
				val %= 1337;
			}
			ans *= val;
			ans %= 1337;
			for (int j = b[i]; j < 10; j++) {
				val *= last_digit;
				val %= 1337;
			}
			last_digit = val;
		}
		return ans;
    }
};
