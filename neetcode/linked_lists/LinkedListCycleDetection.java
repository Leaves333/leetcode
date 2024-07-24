class Solution {
    public boolean hasCycle(ListNode head) {
		ListNode slow = head, fast = head.next;
		while (fast != null && fast.next != null) {
			if (slow == fast) {
				return true;
			}
			slow = slow.next;
			fast = fast.next.next;
		}
		return false;
    }
}
