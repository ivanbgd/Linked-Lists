#include "sll.h"

Node *addNode(int val, Node *curr) {
    Node *node = malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    if (curr != NULL) {
        node->next = curr->next;
        curr->next = node;
    }
    return node;
}

/* Deletes the next node. */
void deleteNode(Node *curr) {
    if ((curr == NULL) || (curr->next == NULL))
        return;
    Node *next = curr->next;
    curr->next = curr->next->next;
    free(next);
}

void destroyList(Node *head) {
    for (Node *curr = head; curr != NULL; ) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
}

/* Reverses entire list. */
/* It's mandatory to set tail to head before calling this function. */
Node *reverseList(Node *head) {
    Node *prev = NULL;
    Node *curr = NULL;
    Node *next = NULL;

    for (curr = head; curr != NULL; ) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

/* Reverses elements in the middle of a list.
   start >= 1
   Returns new tail node. */
Node *reverseInMiddle(Node *head, size_t start, size_t end) {
    Node *prev = NULL;
    Node *curr = NULL;
    Node *next = NULL;
    Node *oldPrev = NULL;
    Node *startNode = NULL;
    Node *endNode = NULL;
    Node *oldNext = NULL;
    Node *tail = NULL;

    oldPrev = traverseList(head, start);
    startNode = curr = oldPrev->next;
    for (size_t i = start; (i < end + 1) && (curr != NULL); ++i) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    endNode = prev;
    oldNext = curr;
    oldPrev->next = endNode;
    startNode->next = oldNext;

    if (curr == NULL) {
        tail = startNode;
    }
    else {
        while (curr) {
            tail = curr;
            curr = curr->next;
        }
    }

    return tail;
}

Node *traverseList(Node *head, size_t dist) {
    Node *curr = head;
    for (size_t i = 0; (i < dist - 1) && (curr->next != NULL); ++i) {
        curr = curr->next;
    }
    return curr;
}

void printList(Node *head) {
    printf("[head] => ");
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        printf("%d => ", curr->value);
    }
    printf("[tail]\n\n");
}

