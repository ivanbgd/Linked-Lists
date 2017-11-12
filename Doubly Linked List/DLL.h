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

#pragma once

#define DLL
#define TEST_DLL

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int key;
    Node *next, *prev;
};

// this would be a constructor of the Node class, of a Node object.
// we can't name it Node, which would be appropriate (constructor should have the same name as the class),
// and I didn't want to name it node because I keep that for variables ("objects").
Node * createNode(int key);

typedef struct List List;

struct List {
    Node *head;
    Node *tail;
    unsigned size;
};

/* this would be a constructor of the List class, of a List object */
List * createList(void);

// we need this destructor, and to invoke it explicitly, because C doesn't have garbage collector
// it destroys all individual nodes in the list, and then the list itself
void destroyList(List *list);

// prints list from head to tail
void printList(List *list);

// prints list from tail to head (backwards)
void printReverse(List *list);

// inserts a node with the key key at the index location index - indexing starts with 0
// if index is greater than current size of the list, inserts the node at the end of the list
void insert(List *list, unsigned index, int key);

// inserts a node with the key key after the first encountered node with the key afterTheKey
// if the node hasn't been found, inserts the new node at the end of the list
void insertAfter(List *list, int afterTheKey, int key);

// inserts node at the beginning of the list
void pushFront(List *list, int key);

// inserts node at the end of the list
void push(List *list, int key);

/* returns key value of the node at the front of the list, and then destroys that node
we can alternatively return the node, without destroying it here, if a caller needs the node, not just its key, and then the caller can destroy it
I find returning the key more logical */
int popFront(List *list);

/* returns key value of the node at the back of the list, and then destroys that node
we could alternatively return the node, without destroying it here, if a caller needs the node, not just its key, and then the caller can destroy it
I find returning the key more logical */
int pop(List *list);

// removes the first encountered node with the given key from the list
// if such a node isn't found, does nothing
void erase(List *list, int key);

// removes all nodes from list, but keeps the list
void clearList(List *list);

// a getter "method", returning size of the list
unsigned getSize(List *list);

// returns found node or NULL, and prints whether it has found it or not
Node * findPrint(List *list, int key);

// returns found node or NULL
Node * find(List *list, int key);

// changes value of a key, if it's in the list; nothing otherwise
void updateKey(List *list, int key, int newKey);

// merges two lists together, by extending the first one by the second one (concatenates list2 to list1)
// the second one is deleted
// doesn't create a new list
// returns list1 in both ways: as a parameter, and as the return value - it doesn't matter what we'll use
List * merge(List *list1, List *list2);

// splits list1 to list1 and list2 after the first occurence of key in list1
// list1 will be updated and returned via function parameter
// returns list2 (containing elements after the key)
// if key isn't found in list1, returns NULL instead - meaning, it will NOT split list1
List * split(List *list1, int key);
