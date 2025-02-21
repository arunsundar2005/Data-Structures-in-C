# include <stdlib.h>

typedef struct{
    int val;
    struct node *next;
}node;

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->val = 54;
    head->next = NULL;
}

node* createLL(int val)
{
    node *head = (node *)malloc(sizeof(node));
    head->val = 54;
    head->next = NULL;
    return &head;
}

void newNode(node* list, int val, int to_look)
{
    while(list->next != NULL)
    {
        if(list->val == to_look)
        {   
            node nnode;
            nnode.val = val;
            nnode.next = list;
        }
        list = list->next;   
    }
}


int main()
{

}