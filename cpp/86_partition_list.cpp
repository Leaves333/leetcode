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
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr)
            return head;

        ListNode less_head = ListNode(), greater_head = ListNode();
        ListNode* less = nullptr;
        ListNode* greater = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (cur->val < x) {
                if (less == nullptr) {
                    less_head.next = cur;
                    less = cur;
                } else {
                    less->next = cur;
                    less = cur;
                }
            } else {
                if (greater == nullptr) {
                    greater_head.next = cur;
                    greater = cur;
                } else {
                    greater->next = cur;
                    greater = cur;
                }
            }
            cur = cur->next;
        }

        if (less_head.next == nullptr) {
            return greater_head.next;
        } else {
            less->next = greater_head.next;
            if (greater != nullptr)
                greater->next = nullptr;
            return less_head.next;
        }

    }
};
