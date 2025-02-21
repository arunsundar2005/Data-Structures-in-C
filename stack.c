# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAX_SIZE 100



typedef struct 
{
    int key;
}element;



element stack[MAX_SIZE]; // creates an array with MAX_SIZE elements. These elements are of the element structure. 
int top = -1;

bool is_full()
{
    return top >= MAX_SIZE;
}

bool is_empty()
{
    return top<=-1;
}

element delete()
{
    if(is_empty()){
        element n;
        return n;
        }
    element del = stack[top];
    top = top-1;
    return del;
}
void stack_full()
{
    if(top == MAX_SIZE-1)
        printf("the stack is full");
}

void add(int *top, element item)
{
    if (*top >= MAX_SIZE -1)
    {
        stack_full();
    }
    stack[++*top] = item;
}

void display()
{
    if(top == -1)
        printf("The list is empty");
    else
    {
        for(int i = 0; i<=top; i++)
        {
            printf("Index : %d\tValue : %d\n", i, stack[i].key);
        }
    }
}

int main()
{
    element i1 = {645};
    element i2 = {598}; 
    add(&top, i1);
    add(&top, i2);
    display();
}