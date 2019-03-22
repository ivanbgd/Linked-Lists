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

    head = reverseList(head);
    printList(head);

    head = reverseList(head);
    tail = addNode(105, tail);
    tail = addNode(106, tail);
    printList(head);

    reverseInMiddle(head, 2, 4);
    printList(head);

    destroyList(head);
    head = NULL;
    printList(head);

    system("pause");
    return 0;
}
