import java.util.Stack;

class Solution {
    public ListNode reverseList(ListNode head) {
       
        // edge case
        if (head == null) {
            return null;
        }

        Stack<ListNode> stack = new Stack<ListNode>();

        while (head.next != null) {
            stack.add(head);
            head = head.next;
        }

        ListNode ans = head;
        while (!stack.empty()) {
            ListNode top = stack.pop();
            head.next = new ListNode(top.val);
            head = head.next;
        }
        return ans;
    
    }
}