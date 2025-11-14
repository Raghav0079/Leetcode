/*Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node *currentLevelStart = root;

    while (currentLevelStart != NULL) {
        struct Node *currentNode = currentLevelStart;
        struct Node *nextLevelStart = NULL;
        struct Node *prevNode = NULL;

        while (currentNode != NULL) {
            if (currentNode->left != NULL) {
                if (prevNode != NULL) {
                    prevNode->next = currentNode->left;
                } else {
                    nextLevelStart = currentNode->left;
                }
                prevNode = currentNode->left;
            }

            if (currentNode->right != NULL) {
                if (prevNode != NULL) {
                    prevNode->next = currentNode->right;
                } else {
                    nextLevelStart = currentNode->right;
                }
                prevNode = currentNode->right;
            }

            currentNode = currentNode->next;
        }

        currentLevelStart = nextLevelStart;
    }

    return root;
}