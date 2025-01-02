#include <bits/stdc++.h>
using namespace std;

struct CacheNode {
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;

    CacheNode(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:

    int capacity;
    map<int, CacheNode*> m;
    CacheNode* head; // oldest node
    CacheNode* tail; // newest node

    LRUCache(int capacity) {
        this->capacity = capacity;
        m = map<int, CacheNode*>();
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(CacheNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(CacheNode* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
    
    int get(int key) {
        if (m.count(key) == 0)
            return -1;
        remove(m[key]);
        insert(m[key]);
        return m[key]->value;
    }
    
    void put(int key, int value) {

        // already has key
        if (m.count(key)) {
            remove(m[key]);
            m[key]->value = value;
            insert(m[key]);
            return;
        }

        // delete oldest key
        if (m.size() >= capacity) {
            m.erase(head->next->key);
            remove(head->next);
        }

        // insert key
        m[key] = new CacheNode(key, value);
        insert(m[key]);

    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
