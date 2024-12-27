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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode front = ListNode();
        front.next = head;

        // check if there are k nodes remaining
        // reverse nodes if so
        
        ListNode* prev = &front;
        while (true) {

            bool enough_nodes = true;
            ListNode* after = prev->next;
            for (int i = 0; i < k; i++) {
                if (after == nullptr) {
                    enough_nodes = false;
                    break;
                }
                after = after->next;
            }

            if (!enough_nodes)
                break;

            ListNode* cur = prev->next;

            for (int i = 0; i < k - 1; i++) {
                ListNode* next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }

            prev = cur;

        }

        return front.next;

    }
};
