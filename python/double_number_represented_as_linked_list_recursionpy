# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):

    carry = False

    def doubleIt(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        if head.next != None:
           self.doubleIt(head.next)

        head.val *= 2
        if self.carry:
            head.val += 1

        self.carry = False
        if head.val >= 10:
            head.val %= 10
            self.carry = True
        
        if self.carry:
            return ListNode(1, head)
        return head