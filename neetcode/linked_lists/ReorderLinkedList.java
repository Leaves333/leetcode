class Solution {
    public void reorderList(ListNode head) {

		// split list into two
		// reverse second half
		// merge lists

		ListNode slow = head, fast = head;
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}

		ListNode prev = null, cur = slow.next;
		slow.next = null;
		while (cur != null) {
			ListNode tmp = cur.next;
			cur.next = prev;
			prev = cur;
			cur = tmp;
		}

		ListNode first = head, second = prev;
		while (second != null) {
			ListNode tmpFirst = first.next;
			ListNode tmpSecond = second.next;
			first.next = second;
			second.next = tmpFirst;
			first = tmpFirst;
			second = tmpSecond;
		}

    }
}
