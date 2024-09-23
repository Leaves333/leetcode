#include <bits/stdc++.h>
using namespace std;

/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
		vector<int> vals;
		ListNode* cur = head;
		while (cur != nullptr) {
			vals.push_back(cur->val);
			cur = cur->next;
		}
		
		int ans = 0;
		for (int i = 0; i < vals.size() / 2; i++) {
			ans = max(ans, vals[i] + vals[vals.size() - i - 1]);
		}
		return ans;
    }
};
