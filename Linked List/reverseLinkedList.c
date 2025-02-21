# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\delNode.c>

void reverse(ll *list, ll *rev_llist);

int main()
{
    ll llist;
    llist.head = NULL;
    int arr[5] = {23, 56, 47, 98, 5642};
    for(int i=0; i<5; i++)
    {
        create(&llist, arr[i]);
    }
    printll(&llist);
    ll r_llist;
    reverse(&llist, &r_llist);
    printll(&r_llist);
    return 1;

}

void reverse(ll *list, ll *rev_llist) {
    node *current = list->head;
    // ll rev_llist;
    rev_llist->head = NULL;

    while (current != NULL) {
        // Create a new node with the current key and add it to the reversed list
        create(rev_llist, current->key);
        node *temp = current->next;
        current = current->next; // Move to the next node
        free(temp);
    }

}