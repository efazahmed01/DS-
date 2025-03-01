#include <stdio.h>
#define MAX 500

struct queue
{
    int v[MAX];
    int front;
    int back;
};

void push(int v, struct queue *q)
{
    if (q->back >= MAX) 
    {
        printf("Queue is full!\n");
        return;
    }
    q->v[q->back++] = v;
}

int pop(struct queue *q)
{
    if (q->front >= q->back) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->v[q->front++];
}

int isFull(struct queue *q)
{
    return q->back >= MAX;
}

int isEmpty(struct queue *q)
{
    return q->front >= q->back;
}

int top(struct queue *q)
{
    if(isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->v[q->front];
}

int main()
{
    struct queue q;
    q.front = 0;
    q.back = 0;
    
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        push(x, &q);
    }

    printf("Top = %d\n", top(&q));
    
    while(!isEmpty(&q))
    {
        printf("Pop = %d\n", pop(&q));
    }
    return 0;
}
