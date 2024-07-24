class Solution {

	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	
		int carry = 0;
		ListNode head = null;
		ListNode cur = null;
	
		while (carry != 0 || l1 != null || l2 != null) {

			if (head == null) {
				head = new ListNode();
				cur = head;
			} else {
				cur.next = new ListNode();
				cur = cur.next;
			}

			int sum = carry;
			if (l1 != null) {
				sum += l1.val;
				l1 = l1.next;
			}
			if (l2 != null) {
				sum += l2.val;
				l2 = l2.next;
			}

			cur.val = sum % 10;
			carry = sum / 10;
			
		}
	
		return head;
	
	}

} 
