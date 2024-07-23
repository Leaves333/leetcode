class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {

		ListNode counter = head;
		int nodes = 0;
		while (counter != null) {
			counter = counter.next;
			nodes++;
		}

		// edge case
		if (n == nodes) {
			return head.next;
		}

		ListNode prev = null, cur = head;
		int curCount = 0, target = nodes - n;
		while (curCount < target) {
			System.out.println("cur: " + cur);
			prev = cur;
			cur = cur.next;
			curCount++;
		}

		if (cur == null) {
			prev.next = null;
		} else {
			prev.next = cur.next;
		}
		return head;

	}
}
