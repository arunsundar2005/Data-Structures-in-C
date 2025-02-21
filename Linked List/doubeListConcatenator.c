# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\doublyLinkedList.c>
dll *createDList(int *arr, int number);

int main()
{
    int arr1[3] = {6, 5, 2};
    int arr2[3] = {5, 8, 9};
    dll *list1 = createDList(arr1, 3);
    dll *list2 = createDList(arr2, 3);
    printll(list1);
    printll(list2);
    concatenator(list1, list2);
    printll(list1);
    return 0;
}


dll *createDList(int *arr, int number)
{
    dll *llist = (dll *)malloc(sizeof(dll)); // Dynamically allocate memory
    if (llist == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Handle allocation failure
    }

    llist->head = NULL; // Initialize the head pointer
    llist->tail = NULL;

    // int *arr = (int *)malloc(number * sizeof(int));
    for (int i = 0; i < number; i++) {
        // printf("Enter the %dth element of the linked list\n", i);
        // scanf("%d", &arr[i]);        // Read elements into the array
        createNode(llist, arr[i]);      // Add elements to the linked list
    }

    return llist; // Return the dynamically allocated list
}

void concatenator(dll *list1, dll *list2)
{
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
}