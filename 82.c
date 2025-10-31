/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode * deleteDuplicates(struct ListNode *head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    struct ListNode *current = head;

    while (current != NULL) {
        bool isDuplicate = false;
        while (current->next != NULL && current->val == current->next->val) {
            isDuplicate = true;
            struct ListNode *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        if (isDuplicate) {
            struct ListNode *temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }

    struct ListNode *result = dummy->next;
    free(dummy);
    return result;
}