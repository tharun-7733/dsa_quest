# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyNode = ListNode(-1)
        cur = dummyNode

        carry = 0

        while l1 or l2:
            sum = carry

            if l1:
                sum = sum + l1.val
            if l2:
                sum = sum + l2.val
            
            newNode = ListNode(sum % 10)
            carry = sum // 10
            cur.next = newNode
            cur = cur.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        if carry:
            carryNode = ListNode(carry)
            cur.next = carryNode

        return dummyNode.next