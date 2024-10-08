#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int start = gas.size() - 1, end = 0;
		int total_gas = gas[start] - cost[start];

		while (start > end) {
			if (total_gas > 0) {
				total_gas += gas[end] - cost[end];
				end++;
			} else {
				start--;
				total_gas += gas[start] - cost[start];
			}
		}
		
		if (total_gas < 0) {
			return -1;
		} else {
			return start;
		}
    }
};
