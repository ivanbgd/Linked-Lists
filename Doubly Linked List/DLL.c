/* Doubly Linked List, with both head and tail pointers, and size field.
I tried to make this as object-oriented as possible.
I created structures for both Node and List, where it's common to have only Node.
Those two structs imitate classes from OOP.
Their names start in capital letters.
It's easier to work with multiple lists this way.
We can also save fields (attributes, properties) like size in List.
Of course, this is slower approach, but it's in OOP manner.
If we need to work with one list only, we can use the faster approach.
OOP or not, I don't want to work with global variables, even though when working with them it is easier to write code. */

#include "DLL.h"

#ifdef DLL

Node * createNode(int key) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

List * createList(void) {
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroyList(List *list) {
    if (!list)
        return;
    else if (!(list->head)) {
        free(list);
        return;
    }
    Node *current = list->head;
    while (current) {
        free(current->prev);
        current = current->next;
    }
    free(list->tail);
    free(list);
}

void printList(List *list) {
    if (!list) {
        printf("\nThe list doesn't exist!\n");
        return;
    }
    Node *current = list->head;
    printf("\n[head] <=>");
    while (current) {
        printf(" %d <=>", current->key);
        current = current->next;
    }
    printf(" [tail]\n");
}

void printReverse(List *list) {
    if (!list) {
        printf("\nThe list doesn't exist!\n");
        return;
    }
    Node *current = list->tail;
    printf("\n[tail] <=>");
    while (current) {
        printf(" %d <=>", current->key);
        current = current->prev;
    }
    printf(" [head]\n");
}

void insert(List *list, unsigned index, int key) {
    Node *node = createNode(key);                               // creating a Node using "constructor"
    Node *next = list->head;                                    // we are inserting at the place where this node has been; that's why it becomes next

    if (!next) {                                                // if the list is empty, there is no next
        list->head = node;
        list->tail = node;
    }

    else if (index < list->size) {
        for (unsigned i = 0; i < index; i++)
            next = next->next;
        if (next->prev)
            next->prev->next = node;
        node->prev = next->prev;
        node->next = next;
        next->prev = node;

        if (index == 0)
            list->head = node;
    }

    else {
        list->tail->next = node;
        node->prev = list->tail;

        list->tail = node;
    }

    list->size++;
}

void insertAfter(List *list, int afterTheKey, int key) {
    Node *node = createNode(key);                               // creating a Node using "constructor"
    Node *prev = find(list, afterTheKey);                       // we are inserting after the found node; that's why it is previous

    // if the list is empty
    if (!list->head) {
        list->head = node;
        list->tail = node;
    }

    // if afterTheKey has been found
    else if (prev) {
        node->next = prev->next;
        if (prev->next)
            prev->next->prev = node;
        prev->next = node;
        node->prev = prev;

        if (!node->next)
            list->tail = node;
    }

    // if afterTheKey hasn't been found
    else {
        list->tail->next = node;
        node->prev = list->tail;

        list->tail = node;
    }

    list->size++;
}

// inserts node at the beginning of the list
void pushFront(List *list, int key) {
    Node *node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->next = list->head;
    node->prev = NULL;

    if (node->next)
        node->next->prev = node;
    else
        list->size = 0;

    list->head = node;
    if (!(list->tail))
        list->tail = node;
    list->size++;
}

// inserts node at the end of the list
void push(List *list, int key) {
    // create a Node using "constructor"
    Node *node = createNode(key);

    node->prev = list->tail;
    //node->next = NULL;                                        // this has already been satisfied in the constructor

    if (node->prev)
        node->prev->next = node;
    else
        list->size = 0;

    list->tail = node;
    if (!(list->head))
        list->head = node;
    list->size++;
}

/* returns key value of the node at the front of the list, and then destroys that node
we can alternatively return the node, without destroying it here, if a caller needs the node, not just its key, and then the caller can destroy it
I find returning the key more logical */
int popFront(List *list) {
    /* it's faster to work with current, because we dereference list->head less times
    we also need it to free current head node */
    Node *current = list->head;

    /* if the list is empty, we return -1, so the caller can check for this - assumes keys are >= 0 */
    if (!current)
        return -1;

    list->size--;

    int result = current->key;
    if (current->next)
        current->next->prev = NULL;

    /* new head */
    list->head = current->next;

    /* if current is the only node in the list list->head has already been assigned NULL in this case, on the previous line) */
    if (!list->head)                                            // = if (!current->next) = if (!list->size)
        list->tail = NULL;

    free(current);
    return result;
}

/* returns key value of the node at the back of the list, and then destroys that node
we could alternatively return the node, without destroying it here, if a caller needs the node, not just its key, and then the caller can destroy it
I find returning the key more logical */
int pop(List *list) {
    /* it's faster to work with current, because we dereference list->tail less times
    we also need it to free current tail node */
    Node *current = list->tail;

    /* if the list is empty, we return -1, so the caller can check for this - assumes keys are >= 0 */
    if (!current)
        return -1;

    list->size--;

    int result = current->key;
    if (current->prev)
        current->prev->next = NULL;

    /* new tail */
    list->tail = current->prev;

    /* if current is the only node in the list (list->tail has already been assigned NULL in this case, on the previous line) */
    if (!list->tail)
        list->head = NULL;

    free(current);
    return result;
}

// removes the first encountered node with the given key from the list
// if such a node isn't found, does nothing
void erase(List *list, int key) {
    Node *node;
    if (node = find(list, key)) {
        list->size--;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        if (node == list->head)
            list->head = node->next;
        if (node == list->tail)
            list->tail = node->prev;
        free(node);
    }
}

// removes all nodes from list, but keeps the list
void clearList(List *list) {
    if (!(list->head))
        return;
    Node *current = list->head;
    while (current) {
        free(current->prev);
        current = current->next;
    }
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// a getter "method", returning size of the list
unsigned getSize(List *list) {
    if (!list) {
        printf("\nThe list doesn't exist!\n");
        return 0;
    }
    return list->size;
}


Node * findPrint(List *list, int key) {
    Node *current = list->head;
    int pos = 0;

    if (!current) {
        printf("Linked list empty.\n");
        return NULL;
    }

    while (current) {
        if (current->key == key) {
            printf("%d found at position %d.\n", key, pos);
            return current;
        }
        current = current->next;
        pos++;
    }

    printf("%d does not exist in the list.\n", key);
    return NULL;
}

Node * find(List *list, int key) {
    Node *current = list->head;

    if (!current)
        return NULL;

    while (current) {
        if (current->key == key)
            return current;
        current = current->next;
    }

    return NULL;
}

void updateKey(List *list, int key, int newKey) {
    Node *node = find(list, key);
    if (node)
        node->key = newKey;
}

List * merge(List *list1, List *list2) {
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;

    list1->tail = list2->tail;
    list1->size += list2->size;
    free(list2);
    return list1;
}

List * split(List *list1, int key) {
    Node *node = find(list1, key);
    if (!node)
        return NULL;
    List *list2 = createList();

    list2->tail = list1->tail;
    list1->tail = node;
    list2->head = node->next;

    if (node->next)
        node->next->prev = NULL;
    node->next = NULL;

    node = list2->head;
    if (!node)
        list2->tail = NULL;
    while (node) {
        list2->size++;
        node = node->next;
    }
    list1->size -= list2->size;

    return list2;
}

#endif // DLL