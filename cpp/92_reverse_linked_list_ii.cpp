#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

		ListNode* node_before_reversal = head;
		ListNode* cur = head;
		int index = 1;

		while (index < left) {
			node_before_reversal = cur;
			cur = cur->next;
			index++;
		}

		ListNode* last_reversed_node = cur;
		ListNode* prev = nullptr;
		while (index < right) {
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur->next;
			cur = next;
			index++;
		}

		if (right - left > 0) {
			last_reversed_node->next = cur;
		}
		if (node_before_reversal != nullptr) {
			node_before_reversal->next = prev;
		}

		return head;
    }
};
