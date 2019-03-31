#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Node *next;
    int value;
};

Node *addNode(int val, Node *curr);
void deleteNode(Node *curr);
void destroyList(Node *head);
Node *reverseList(Node *head);
Node *reverseInMiddle(Node *head, size_t start, size_t end);
Node *traverseList(Node *head, size_t numElts);
void printList(Node *head);

