'''Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.'''


class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: Optional[ListNode]
        :type left: int
        :type right: int
        :rtype: Optional[ListNode]
        """
        if not head:
            return None

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        for _ in range(left - 1):
            prev = prev.next

        curr = prev.next

        for _ in range(right - left):
            next_temp = curr.next
            curr.next = next_temp.next
            next_temp.next = prev.next
            prev.next = next_temp

        return dummy.next
    
        