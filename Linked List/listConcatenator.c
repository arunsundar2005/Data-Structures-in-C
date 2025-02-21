# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\delNode.c>
ll *createll(int *arr, int number);
void concatenator(ll *l1, ll *l2);
int start2() // replace the name as 'main' when running the file as such
{
    int arr1[3] = {6,8,3};
    int arr2[4] = {9, 8, 2};
    ll *list1 = createll(arr1, 3); // try passing an array with the list data, try pointer of it
    ll *list2 = createll(arr2, 3);
    printll(list1);
    printll(list2);
    concatenator(list1, list2);
    printll(list1);

}

ll *createll(int *arr, int number) {
    ll *llist = (ll *)malloc(sizeof(ll)); // Dynamically allocate memory
    if (llist == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Handle allocation failure
    }

    llist->head = NULL; // Initialize the head pointer

    // int *arr = (int *)malloc(number * sizeof(int));
    for (int i = 0; i < number; i++) {
        // printf("Enter the %dth element of the linked list\n", i);
        // scanf("%d", &arr[i]);        // Read elements into the array
        create(llist, arr[i]);      // Add elements to the linked list
    }

    return llist; // Return the dynamically allocated list
}



void concatenator(ll *l1, ll *l2)
{
    node *current1 = l1->head;
    // node *current2 = l2->head;
    while(current1->next != NULL)
    {
        current1 = current1->next;
    }
    // while (current2->next != NULL)
    // {
    //     current2 = current2->next;
    // }
    current1->next = l2->head;
}

// Create a concatenator function