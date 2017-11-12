#include "DLL.h"

#ifdef TEST_DLL

void testA(void) {
    printf("*** Test A ***\n");

    // this is how we create List "objects" - these are pointers to them
    List *list1 = createList(), *list2 = createList(), *list3 = createList();

    Node *node = NULL;

    pushFront(list1, 10);
    pushFront(list1, 20);
    pushFront(list1, 30);
    pushFront(list1, 1);
    pushFront(list1, 40);
    pushFront(list1, 56);

    push(list2, 10);
    push(list2, 20);
    push(list2, 30);
    push(list2, 1);
    push(list2, 40);
    push(list2, 56);

    push(list3, 0);
    pushFront(list3, 1);
    push(list3, 2);
    pushFront(list3, 3);
    push(list3, 4);
    pushFront(list3, 5);
    push(list3, 6);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    printList(list2);
    printReverse(list2);
    printf("\nList2 size: %u\n", getSize(list2));

    printList(list3);
    printReverse(list3);
    printf("\nList3 size: %u\n", getSize(list3));

    printf("\nList3:\n");
    if (node = findPrint(list3, 1))
        printf("%d found.\n", node->key);
    else
        printf("1 not found.\n");
    if (node = findPrint(list3, 13))
        printf("%d found.\n", node->key);
    else
        printf("13 not found.\n");

    updateKey(list3, 4, 44);
    updateKey(list3, 14, 144);

    printList(list3);
    printReverse(list3);

    destroyList(list1);
    destroyList(list2);
    destroyList(list3);

    printf("\n\n");
}

void testB(void) {
    printf("*** Test B ***\n");

    List *list1 = createList();

    push(list1, 0);
    pushFront(list1, 1);
    push(list1, 2);
    pushFront(list1, 3);
    push(list1, 4);
    pushFront(list1, 5);
    push(list1, 6);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    clearList(list1);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    destroyList(list1);

    printf("\n\n");
}

void testC(void) {
    printf("*** Test C ***\n");

    List *list1 = createList();
    int key;
    unsigned size = 0;

    push(list1, 0);
    pushFront(list1, 1);
    push(list1, 2);
    pushFront(list1, 3);
    push(list1, 4);
    pushFront(list1, 5);
    push(list1, 6);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    key = popFront(list1);
    printf("\nKey popped off front: %d\n", key);
    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    key = pop(list1);
    printf("\nKey popped off back: %d\n", key);
    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    for (size_t i = 0, size = list1->size; i < size; i++) {
        key = popFront(list1);
        printf("\nKey popped off front: %d\n", key);
        printList(list1);
        printReverse(list1);
        printf("\nList1 size: %u\n", getSize(list1));
    }

    destroyList(list1);

    printf("\n\n");
}

void testD(void) {
    printf("*** Test D ***\n");

    List *list1 = createList();
    int key;
    unsigned size = 0;

    push(list1, 0);
    pushFront(list1, 1);
    push(list1, 2);
    pushFront(list1, 3);
    push(list1, 4);
    pushFront(list1, 5);
    push(list1, 6);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    key = popFront(list1);
    printf("\nKey popped off front: %d\n", key);
    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    key = pop(list1);
    printf("\nKey popped off back: %d\n", key);
    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    for (size_t i = 0, size = list1->size; i < size; i++) {
        key = pop(list1);
        printf("\nKey popped off back: %d\n", key);
        printList(list1);
        printReverse(list1);
        printf("\nList1 size: %u\n", getSize(list1));
    }

    destroyList(list1);

    printf("\n\n");
}

void testE(void) {
    printf("*** Test E ***\n");

    List *list1 = createList();
    int key = 0;
    unsigned size = 0;

    push(list1, 0);
    pushFront(list1, 1);
    push(list1, 2);
    pushFront(list1, 3);
    push(list1, 4);
    pushFront(list1, 5);
    push(list1, 6);

    erase(list1, 43);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    for (size_t i = 0, size = list1->size + 1; i < size; i++) {
        erase(list1, i);
        printList(list1);
        printReverse(list1);
        printf("\nList1 size: %u\n", getSize(list1));
    }

    destroyList(list1);

    printf("\n\n");
}

void testF(void) {
    printf("*** Test F ***\n");

    // this is how we create List "objects" - these are pointers to them
    List *list1 = createList(), *list2 = createList();

    Node *node = NULL;

    pushFront(list1, 6);
    pushFront(list1, 5);
    pushFront(list1, 4);
    pushFront(list1, 3);
    pushFront(list1, 2);
    pushFront(list1, 1);

    push(list2, 10);
    push(list2, 11);
    push(list2, 12);
    push(list2, 13);
    push(list2, 14);
    push(list2, 15);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    printList(list2);
    printReverse(list2);
    printf("\nList2 size: %u\n", getSize(list2));

    merge(list1, list2);                                        // we can assign this to list1, but we don't need to

    // list2 doesn't exist from here on, after merge

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    printf("\nList1:\n");
    if (node = findPrint(list1, 13))
        printf("%d found.\n", node->key);
    else
        printf("13 not found.\n");
    if (node = findPrint(list1, 73))
        printf("%d found.\n", node->key);
    else
        printf("73 not found.\n");

    erase(list1, 13);
    popFront(list1);
    pop(list1);
    push(list1, 20);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    destroyList(list1);

    printf("\n\n");
}

void testG(void) {
    printf("*** Test G ***\n");

    List *list1 = createList(), *list2 = NULL;

    Node *node = NULL;

    pushFront(list1, 6);
    pushFront(list1, 5);
    pushFront(list1, 4);
    pushFront(list1, 3);
    pushFront(list1, 2);
    pushFront(list1, 1);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    list2 = split(list1, 6);

    printList(list1);
    printReverse(list1);
    printf("\nList1 size: %u\n", getSize(list1));

    printList(list2);
    printReverse(list2);
    printf("\nList2 size: %u\n", getSize(list2));

    destroyList(list1);
    destroyList(list2);

    printf("\n\n");
}

void testH(void) {
    printf("*** Test H ***\n");

    List *list = createList();

    insert(list, 7, 8);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    erase(list, 8);
    clearList(list);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    for (int i = 1; i < 6; i++)
        insert(list, i, i);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insert(list, 10, 6);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insert(list, 0, 0);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insert(list, 7, 8);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insert(list, 7, 7);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insert(list, 3, 3);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insert(list, 3, 33);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    destroyList(list);

    printf("\n\n");
}

void testI(void) {
    printf("*** Test I ***\n");

    List *list = createList();

    insertAfter(list, 7, 8);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    erase(list, 8);
    clearList(list);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    for (int i = 1; i < 6; i++)
        insertAfter(list, i - 1, i);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insertAfter(list, 10, 6);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insertAfter(list, 0, 7);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insertAfter(list, 7, 9);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insertAfter(list, 7, 8);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insertAfter(list, 3, 3);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    insertAfter(list, 3, 33);

    printList(list);
    printReverse(list);
    printf("\nList size: %u\n", getSize(list));

    destroyList(list);

    printf("\n\n");
}


int main() {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();
    testG();
    testH();
    testI();

    char c;
    printf("Success!\nPress <Enter>.");
    c = getchar();
    return 0;
}

#endif // TEST_DLL
