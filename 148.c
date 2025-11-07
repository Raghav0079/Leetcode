#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

/*Given the head of a linked list, return the list after sorting it in ascending order*/
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* sortList(struct ListNode* head){
    if (!head || !head->next) return head;

    // Find the middle point using the slow and fast pointer technique
    struct ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL; // Split the list into two halves

    // Recursively sort the two halves
    struct ListNode *l1 = sortList(head);
    struct ListNode *l2 = sortList(slow);

    // Merge the two sorted halves
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2; // Append the remaining elements

    return dummy.next;
}