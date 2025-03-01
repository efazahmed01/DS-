#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

int isEmpty(struct Node* top) 
{
    return top == NULL;
}

void push(struct Node** top, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top) 
{
    if (isEmpty(*top)) 
    {
        printf("Stack Empty\n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

int peek(struct Node* top) 
{
    if (isEmpty(top)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(struct Node* top) 
{
    if (isEmpty(top)) 
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* top = NULL;

    int n;
    scanf("%d", &n);
    while (n--) 
    {
        int x;
        scanf("%d", &x);
        push(&top, x);
    }

    display(top);
    printf("Top element: %d\n", peek(top));

    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    
    display(top);
    printf("Top element: %d\n", peek(top));

    return 0;
}

