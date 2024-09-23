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
    ListNode* oddEvenList(ListNode* head) {

		ListNode* cur_odd = nullptr;
		ListNode* cur_even = nullptr;
		ListNode* odd_head = nullptr;
		ListNode* even_head = nullptr;

		ListNode* cur = head;
		int i = 1;
		while (cur != nullptr) {
			if (i % 2 == 0) {
				if (even_head == nullptr) {
					even_head = cur;
					cur_even = even_head;
				} else {
					cur_even->next = cur;
					cur_even = cur_even->next;
				}
			} else {
				if (odd_head == nullptr) {
					odd_head = cur;
					cur_odd = odd_head;
				} else {
					cur_odd->next = cur;
					cur_odd = cur_odd->next;
				}
			}
			cur = cur->next;
			i++;
		}

		if (odd_head == nullptr) {
			return nullptr;
		}
		cur_odd->next = even_head;
		if (cur_even != nullptr) {
			cur_even->next = nullptr;
		}
		return odd_head;

    }
};
