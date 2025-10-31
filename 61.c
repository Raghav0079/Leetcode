/*Given the head of a linked list, rotate the list to the right by k places*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct ListNode* current = head;
    int length = 1;

    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    current->next = head;

    k = k % length;
    int stepsToNewHead = length - k;

    struct ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}