# include <stdio.h>
# include <F:\Arun\Practise\Data Structures in C\Linked List\listConcatenator.c>


node *middle_element(ll *list);

int main()
{
    int arr[5] = {5,67,2,39,65};
    ll *list = createll(arr, 5);
    printf("\nLinked list created with 5 elements\n");
    printll(list);
    
    node *mid = middle_element(list);
    printf("The key of the middle element is %d", mid->key);
}


node *middle_element(ll *list)
{
    node *slow = list->head;
    node *fast = list->head;

    while(fast->next!=NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // printf("The value of the middle element is %d", slow->key);

    return slow;
}