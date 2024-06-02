from queue import PriorityQueue

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        q = PriorityQueue()
        for i in range(len(lists)):
            if lists[i] != None:
                q.put((lists[i].val, i))
        
        head = None
        while not q.empty():

            idx = q.get()[1]
            
            if head == None:
                head = ListNode(lists[idx].val, lists[idx].next)
                last = head
            else:
                last.next = ListNode(lists[idx].val, lists[idx].next)
                last = last.next

            if lists[idx].next != None:
                q.put((lists[idx].next.val, idx))
                lists[idx] = lists[idx].next

        return head