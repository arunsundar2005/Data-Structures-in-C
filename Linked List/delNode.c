# include <F:\Arun\Practise\Data Structures in C\Linked List\linkedList.c>

void create(ll *list, int data);
void printll(ll *list);
void delstart(ll *list);
void delEnd(ll *list);
void delNode(ll *list, int key);

void start1()
{
    ll llist;
    llist.head = NULL;
    int arr[5] = {23, 56, 47, 98, 5642};
    for(int i=0; i<5; i++)
    {
        create(&llist, arr[i]);
    }
    printll(&llist);
    delNode(&llist, 47);
    printll(&llist);
    delstart(&llist);
    printll(&llist);
    delEnd(&llist);
    printll(&llist);
}

void printll(ll *list)
{
    node *current = list->head;
    int c = 0;
    while(current != NULL)
    {
        if(c>20)
        {
            printf("\n\n\nLoop Detected\n\n\n");
            return;
        }
        printf("%d -> ", current->key);
        current = current->next;
        c += 1;
    }
    printf("\n");
}

void create(ll *list, int data)
{
   node *newNode = (node*)malloc(sizeof(node));
   newNode->key = data;
   newNode->next = list->head;
   list->head = newNode;    
}

void delstart(ll *list)
{
    if(list->head == NULL)
        return;
    node *n = list->head;
    free(list->head);
    list->head = n->next;
}

void delEnd(ll *list)
{
    node *current = list->head;
    while(current->next->next!= NULL)
    {
       current = current->next;
    }
    free(current->next);
    current->next = NULL;
    
}

void delNode(ll *list, int key)
{
    node *current = list->head;
    while(current->next != NULL)
    {
        if(current->next->key == key)
        {
            node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }

        current = current->next;
    }
}