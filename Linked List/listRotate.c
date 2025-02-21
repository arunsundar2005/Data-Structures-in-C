# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\listConcatenator.c>
void rotate(ll *list, int rotateBy);

int main()
{
    int arr[5] = {68,5,3,9,45};
    ll *llist = createll(arr, 5);
    printll(llist);
    rotate(llist, 2);
    printll(llist);
}

void rotate(ll *list, int rotateBy)
{
    node *current = list->head;
    int length = 1;
    while(current->next != NULL)
    {
        length++;
        current = current->next;
    }
    // printf("\n%d", current->key);
    // printf("\n%s", current->next );
    // printf("length:%d", length);
    // return current->key;
    

    int moveby = length-(rotateBy % length)-1;
    node *newTail = list->head;
    for(int i=0; i<moveby; i++)
    {
        newTail = newTail->next;
    }

    node *newHead = newTail->next;
    current->next = list->head;
    newTail->next= NULL;
    list->head = newHead;

}