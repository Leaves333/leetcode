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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr)
            return head;

        auto cur = head;
        int length = 0;
        while (cur != nullptr) {
            cur = cur->next;
            length++;
        }

        auto fast = head, slow = head;
        for (int i = 0; i < k % length; i++) {
            fast = fast->next;
            if (fast == nullptr)
                fast = head;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;

    }
};
