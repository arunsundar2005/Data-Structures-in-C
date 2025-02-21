# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\delNode.c>


int main()
{
    ll llist;
    llist.head = NULL;
    int arr[5] = {23, 56, 47, 98, 5642};
    for(int i=0; i<5; i++)
    {
        create(&llist, arr[i]);
    }
    

    // making the linked list to form a loop
    node *current = llist.head;
    while(current != NULL)
    {
        node *one;
        node *two;

        
        current = current->next;
    }

}