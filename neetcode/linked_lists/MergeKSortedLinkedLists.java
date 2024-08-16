import java.util.PriorityQueue;

class HeapNode implements Comparable<HeapNode> {
    public int priority;
    public int index;

    public HeapNode(int prio, int idx) {
        priority = prio;
        index = idx;
    }

    @Override
    public int compareTo(HeapNode arg0) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'compareTo'");
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        return null;
    }
}
