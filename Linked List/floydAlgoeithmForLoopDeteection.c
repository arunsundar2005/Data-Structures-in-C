# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\delNode.c>

void createLoop(ll *list, int loopPosition);
void loopDetector(ll *list);


int main()
{
    ll llist;
    llist.head = NULL;

    // Create the linked list
    create(&llist, 10);
    create(&llist, 20);
    create(&llist, 30);
    create(&llist, 40);

    // Print the list before creating a loop
    printf("Original List: ");
    printll(&llist);

    // Create a loop at position 2 (1-based index)
    createLoop(&llist, 2);

    // Print the list after creating a loop
    printll(&llist);
    loopDetector(&llist);
    printll(&llist);

    return 0;
}

void createLoop(ll *list, int loopPosition) {
    if (list->head == NULL) {
        printf("The list is empty. Cannot create a loop.\n");
        return;
    }

    node *current = list->head;
    node *loopNode = NULL;
    int position = 1;

    // Traverse the list to find the loop position and the last node
    while (current->next != NULL) {
        if (position == loopPosition) {
            loopNode = current; // Save the node at the loop position
        }
        current = current->next;
        position++;
    }

    // If loopPosition is valid, create the loop
    if (loopNode != NULL) {
        current->next = loopNode; // Link the last node to the loop node
        printf("Loop created at position %d (node with key = %d).\n", loopPosition, loopNode->key);
    } else {
        printf("Invalid loop position. No loop created.\n");
    }
}


void loopDetector(ll *list)
{
    node *slow = (node *)malloc(sizeof(node));
    node *fast = (node *)malloc(sizeof(node));

    slow = list->head;
    fast = list->head;

    while(slow->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            
            printf("Loop Detected at the node with the key %d\n", slow->next->key);
            slow->next = NULL;
            printf("Loop Deleted Successfully\n");
        }
        
    }
    
}