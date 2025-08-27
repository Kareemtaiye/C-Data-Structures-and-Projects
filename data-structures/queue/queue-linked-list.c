#include <stdio.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
