# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        result=ListNode(None)
        head=result
        while l1 and l2:
            if l1.val < l2.val:
                result.next=ListNode(l1.val)
                result=result.next
                l1=l1.next
            else:
                result.next=ListNode(l2.val)
                result=result.next
                l2=l2.next
        if l1 != None:
            result.next=l1
        if l2 != None:
            result.next=l2
        return head.next
