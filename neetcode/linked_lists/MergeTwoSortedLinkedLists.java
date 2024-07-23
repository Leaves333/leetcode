class Solution {
	public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

		ListNode head = null;
		ListNode cur = new ListNode();

		while (list1 != null || list2 != null) {
			if (list1 == null) {
				cur.next = new ListNode(list2.val);
				cur = cur.next;
				list2 = list2.next;
			} else if (list2 == null) {
				cur.next = new ListNode(list1.val);
				cur = cur.next;
				list1 = list1.next;
			} else if (list2.val < list1.val) {
				cur.next = new ListNode(list2.val);
				cur = cur.next;
				list2 = list2.next;
			} else {
				cur.next = new ListNode(list1.val);
				cur = cur.next;
				list1 = list1.next;
			}

			if (head == null) {
				head = cur;
			}
		}

		return head;
	}
}
