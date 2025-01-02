#include <bits/stdc++.h>
#include <cstdio>
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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) {
            return head;
        }

        ListNode tmp = ListNode();
        tmp.next = head;

        auto prev = &tmp;
        auto cur = tmp.next;
        bool skip = false;
        while (cur->next != nullptr) {
            auto next = cur->next;
            if (cur->val == next->val) {
                prev->next = cur->next;
                skip = true;
            } else if (skip) {
                prev->next = cur->next;
                skip = false;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        if (skip) {
            prev->next = cur->next;
        }

        return tmp.next;

    }
};
