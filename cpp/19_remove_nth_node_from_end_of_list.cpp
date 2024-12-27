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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        for (int i = 0; i < n; i++)
            first = first->next;

        ListNode* second = head;
        ListNode* prev = nullptr;
        while (first != nullptr) {
            first = first->next;
            prev = second;
            second = second->next;
        }

        if (prev == nullptr) {
            return head->next;
        } else {
            prev->next = second->next;
            return head;
        }
    }
};
