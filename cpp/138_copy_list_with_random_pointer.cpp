#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

		unordered_map<Node*, Node*> map;
		Node* cur = head;
		Node* prev = nullptr;

		while (cur != nullptr) {
			map[cur] = new Node(cur->val);
			if (prev != nullptr) {
				prev->next = map[cur];
				prev = prev->next;
			} else {
				prev = map[cur];
			}
			cur = cur->next;
		}

		cur = head;
		while (cur != nullptr) {
			map[cur]->random = map[cur->random];
			cur = cur->next;
		}
		
		return map[head];
    }
};
