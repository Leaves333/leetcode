#include <bits/stdc++.h>
#include <queue>
using namespace std;

class MedianFinder {
public:

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int size;

    MedianFinder() {
        max_heap = priority_queue<int>();
        min_heap = priority_queue<int, vector<int>, greater<int>>();
        size = 0;
    }
    
    void addNum(int num) {

        size++;
        if (max_heap.empty() || num < max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);

        // keep heaps balanced
        while (min_heap.size() > max_heap.size()) {
            int top = min_heap.top();
            min_heap.pop();
            max_heap.push(top);
        }

        while (min_heap.size() < size / 2) {
            int top = max_heap.top();
            max_heap.pop();
            min_heap.push(top);
        }

    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size())
            return ((double) max_heap.top() + min_heap.top()) / 2.0;
        else
            return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
