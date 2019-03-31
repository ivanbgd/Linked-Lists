#include "sll.h"

int main(void) {
    Node *head = NULL;
    Node *tail = NULL;
    Node *curr = NULL;

    head = tail = addNode(100, head);
    printf("head: %d\n\n", head->value);

    for (size_t i = 1; i < 5; ++i) {
        tail = addNode(100 + i, tail);
    }
    printList(head);

    curr = traverseList(head, 2);
    deleteNode(curr);
    printList(head);

    curr = traverseList(head, 2);
    addNode(102, curr);
    printList(head);

    tail = head;    /* MANDATORY before a call to reverseList()!!! */
    head = reverseList(head);
    printList(head);

    tail = addNode(99, tail);
    tail = addNode(98, tail);
    printList(head);

    tail = traverseList(head, 6);   // We're deleting the very last node!
    deleteNode(tail);               // Deletes the next node.
    tail = traverseList(head, 5);   // We're deleting the very last node!
    deleteNode(tail);
    printList(head);
        
    tail = head;
    head = reverseList(head);
    tail = addNode(105, tail);
    tail = addNode(106, tail);
    printList(head);

    printf("\n\nReverse in middle:\n\n");

    tail = reverseInMiddle(head, 2, 4);
    printList(head);

    tail = addNode(107, tail);
    tail = addNode(108, tail);
    printList(head);

    tail = reverseInMiddle(head, 2, 4);
    printList(head);

    tail = traverseList(head, 8);   // We're deleting the very last node!
    deleteNode(tail);
    tail = traverseList(head, 7);   // We're deleting the very last node!
    deleteNode(tail);
    printList(head);

    tail = reverseInMiddle(head, 1, 6);
    printList(head);

    tail = addNode(107, tail);
    tail = addNode(108, tail);
    printList(head);

    tail = reverseInMiddle(head, 1, 6);
    printList(head);

    tail = traverseList(head, 8);   // We're deleting the very last node!
    deleteNode(tail);
    tail = traverseList(head, 7);   // We're deleting the very last node!
    deleteNode(tail);
    printList(head);

    destroyList(head);
    head = NULL;
    printList(head);

    system("pause");
    return 0;
}

