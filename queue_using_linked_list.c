#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

int isEmpty(struct Node* front) 
{
    return front == NULL;
}

void enqueue(struct Node** front, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(*front)) 
    {
        *front = newNode;
        return;
    }

    struct Node* temp = *front;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dequeue(struct Node** front) 
{
    if (isEmpty(*front)) 
    {
        printf("Queue Empty\n");
        return;
    }

    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}

int peek(struct Node* front) 
{
    if (isEmpty(front)) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}


void display(struct Node* front) 
{
    if (isEmpty(front)) 
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* front = NULL;

    int n;
    scanf("%d", &n);
    while (n--) 
    {
        int x;
        scanf("%d", &x);
        enqueue(&front, x);
    }

    display(front);
    printf("Front element: %d\n", peek(front));

    dequeue(&front);
    display(front);
    printf("Front element: %d\n", peek(front));

    return 0;
}

