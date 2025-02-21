#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int key;
    struct node *prev;
    struct node *next;
} node;

// Doubly linked list structure
typedef struct dll {
    node *head;
    node *tail;
} dll;

// Function prototypes
void createNode(dll *list, int data);
void printll(dll *list);
void deleteEnd(dll *list);
void insertStart(dll *list, int data);

int start() {
    dll d_list;
    d_list.head = NULL;
    d_list.tail = NULL;

    createNode(&d_list, 352);
    createNode(&d_list, 264);
    createNode(&d_list, 545);
    createNode(&d_list, 656);
    createNode(&d_list, 899);
    createNode(&d_list, 849);

    printll(&d_list);

    insertStart(&d_list, 321);
    printll(&d_list);

    deleteEnd(&d_list);
    printll(&d_list);

    return 0;
}

void createNode(dll *list, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->key = data;
    newNode->next = NULL; // New node is always the last node
    newNode->prev = list->tail; // Link the new node to the current tail

    if (list->tail != NULL) {
        list->tail->next = newNode; // Update the current tail's next pointer
    } else {
        list->head = newNode; // If the list is empty, the new node is the head
    }

    list->tail = newNode; // Update the tail to the new node
}

void printll(dll *list) {
    printf("\n");
    if (list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The head of the linked list is the node with the key %d\n", list->head->key);

    node *current = list->head;
    printf("Linked List (Forward): ");
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("\n");

    printf("The tail of the linked list is the node with the key %d\n", list->tail->key);
}

void insertStart(dll *list, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->key = data;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode; // Update tail if the list is empty
    }
    list->head = newNode;
}

void deleteEnd(dll *list) {
    if (list->tail == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    node *temp = list->tail;

    if (list->tail->prev != NULL) {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    } else {
        list->head = NULL; // If only one node exists, update head
        list->tail = NULL; // Update tail
    }

    free(temp);
}
