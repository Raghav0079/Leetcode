'''Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.'''

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy=ListNode(0)
        dummy.next=head
        prev=dummy
        curr=head
        while curr:
            while curr.next and curr.val==curr.next.val:
                curr=curr.next
            if prev.next==curr:
                prev=prev.next
            else:
                prev.next=curr.next
            curr=curr.next
        return dummy.next
    