#include <stdio.h>
#include <stdbool.h>
#define MAX 500

struct stack 
{
    int v[MAX];
    int cs;
};

bool isFull(struct stack *s) 
{
    return s->cs == MAX;
}

bool isEmpty(struct stack *s) 
{
    return s->cs == 0;
}

void push(int v, struct stack *s) 
{
    if(isFull(s))
        printf("FULL\n");
    else    
        s->v[s->cs++] = v;
}

int pop(struct stack *s) 
{
    if(isEmpty(s))
        return -1;
    return s->v[--s->cs];
}

int top(struct stack *q) 
{
    if(isEmpty(q))
        return -1;  
    return q->v[q->cs - 1];  
}

int main() 
{
    struct stack s;
    s.cs = 0;
    int n;
    scanf("%d", &n);
    
    while(n--) 
    {
        int x;
        scanf("%d", &x);
        push(x, &s);
    }


    for(int i = 0; i < s.cs; i++) 
    {
        printf("%d ", s.v[i]);
    }

    printf("\nPop value = %d\n", pop(&s));
    if(isFull(&s)) 
        printf("FULL\n");
    else    
        printf("Not FULL\n");

    if(isEmpty(&s))
        printf("Empty\n");
    else
        printf("Not Empty\n");


    printf("Top = %d\n", top(&s));  
            
    return 0;
}
