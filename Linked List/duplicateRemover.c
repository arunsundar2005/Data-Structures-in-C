// The assumption is that the list is already sorted.

# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\listConcatenator.c>

void findDuplicate(ll *list);

int main()
{
    int arr[6] = {1,3,3,4,5,6};
    ll *list = createll(arr, 6);
    printf("Created a sorted linked list with 6 elements");
    findDuplicate(list);
}

void findDuplicate(ll *list)
{
    node *current = list->head;
    while(current != NULL)
    {
        if(current->key == current->next->key)
        {
            printf("Duplicate Entry Found...\n");
            printf("Duplicate Element : %d\n", current->key);
            node *temp;
            temp = current->next;
            current->next = current->next->next;
            free(temp);

            current = current->next;
        }
    }
}