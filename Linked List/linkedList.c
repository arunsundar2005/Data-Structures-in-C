# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}node;

typedef struct ll{
    node *head;
}ll;