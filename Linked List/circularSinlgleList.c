# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\delNode.c>
# include <stdbool.h>

ll* create_circular_ll(int arr[], int length);
node* create_node(int data);
int main()
{
    int arr[5] = {9,4,3,8,2};
    ll *cll = create_ll(arr, 5);
    printcll(cll);
}

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->key = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a linked list from an array
ll* create_circular_ll(int arr[], int length) {
    if (length == 0) return NULL;
    
    ll *list = (ll*)malloc(sizeof(ll));
    list->head = create_node(arr[0]);
    if (!list->head) return NULL;
    
    node* current = list->head;
    for (int i = 1; i < length; i++) {
        current->next = create_node(arr[i]);
        if (!current->next) return list; // Return the partially created list if allocation fails
        if (arr[i] == arr[length-1]) current->next->next = list->head;
        current = current->next;
    }
    
    return list;
}

void printcll(ll *list)
{
    printf("\n");
    node *current = list->head;
    while(current->next != list->head)
    {
        printf("%d -> ", current->key);
    }
    printf("\n");
}