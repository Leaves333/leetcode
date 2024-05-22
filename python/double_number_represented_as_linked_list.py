# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def doubleIt(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        num = 0
        while head != None:
            num *= 10
            num += head.val
            head = head.next
        num *= 2

        if num == 0:
            return ListNode(0, None)

        ans = ListNode(num % 10, None)
        while num > 0:
            num = num // 10
            ans = ListNode(num % 10, ans)
        
        return ans.next
