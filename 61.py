'''Given the head of a linked list, rotate the list to the right by k places'''

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        if not head:
            return None
        # Compute the length of the list and get the tail node
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1
        # Make the list circular
        tail.next = head
        # Find the new tail: (length - k % length - 1)th node
        # and the new head: (length - k % length)th node
        k = k % length
        steps_to_new_head = length - k
        new_tail = head
        for _ in range(steps_to_new_head - 1):
            new_tail = new_tail.next
        new_head = new_tail.next
        # Break the circle
        new_tail.next = None
        return new_head
    
    