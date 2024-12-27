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

        if (left == right)
            return head;

        ListNode tmp = ListNode();
        tmp.next = head;

        ListNode* prev = &tmp;
        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* cur = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return tmp.next;

    }
};
