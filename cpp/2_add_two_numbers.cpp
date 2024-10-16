#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode *a = l1, *b = l2;
		ListNode *ans_head = nullptr;
		ListNode *cur = nullptr;

		bool carry = false;
		while (l1 != nullptr || l2 != nullptr || carry) {

			int value = carry;
			if (l1 != nullptr) {
				value += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				value += l2->val;
				l2 = l2->next;
			}

			
			carry = value / 10;
			if (cur == nullptr) {
				ans_head = new ListNode(value % 10, nullptr);
				cur = ans_head;
			} else {
				cur->next = new ListNode(value % 10, nullptr);
				cur = cur->next;
			}
		}

		return ans_head;
    }
};
