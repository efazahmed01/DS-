#include<stdio.h>
#include<stdlib.h>

struct node
{
    int v;
    struct node *next;
};

int isEmpty(struct node *q)
{
    return q == NULL;
}

void push(struct node **q,int v)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->v = v;
    newnode->next = *q;
    *q = newnode;
}

int pop(struct node **q)
{
    struct node *top = *q;
    if(top == NULL)
    {
        printf("Empty\n");
        return -1;
    }
    int pop_value = top->v;
    *q = (*q)->next;
    free(top);
    return pop_value;
}

int main()
{
    struct node *q = NULL;
    struct node *qq = NULL;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        push(&q,x);
    }
    while(q != NULL)
    {
        push(&qq,pop(&q));
    }

    struct node *temp = qq;
    while(temp != NULL)
    {
        printf("%d ",temp->v);
        temp = temp->next;
    }

}