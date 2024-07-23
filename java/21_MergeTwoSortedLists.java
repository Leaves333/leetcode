/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode ans = null;
        ListNode head = null;
        
        while (list1 != null || list2 != null) {
           
            if (ans == null) {
                head = new ListNode();
                ans = head;
            } else {
                ans.next = new ListNode();
                ans = ans.next;
            }

            if (list2 == null) {
                ans.val = list1.val;
                list1 = list1.next;
            } else if (list1 == null) {
                ans.val = list2.val;
                list2 = list2.next;
            } else if (list1.val < list2.val) {
                ans.val = list1.val;
                list1 = list1.next;
            } else {
                ans.val = list2.val;
                list2 = list2.next;
            }
        }
    
        return head;

    }
}