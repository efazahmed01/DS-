#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int v;
    struct node *next;
};

void insert_at_begin(struct node **head, int v) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->v = v;
    newnode->next = *head;
    *head = newnode;
}

void insert_at_end(struct node **head, int v) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->v = v;
    newnode->next = NULL;
    if (*head == NULL) 
    {
        *head = newnode;
        return;
    }
    struct node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
}

void insert_at_any_pos(struct node **head, int pos, int v) 
{
    if (pos == 1) 
    {
        insert_at_begin(head, v);
        return;
    }
    struct node *tmp = *head;
    for (int i = 1; i < pos - 1 && tmp != NULL; i++) 
    {
        tmp = tmp->next;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->v = v;
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete_at_begin(struct node **head) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void delete_at_end(struct node **head) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *tmp = *head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

void delete_at_any_pos(struct node **head, int pos) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) 
    {
        delete_at_begin(head);
        return;
    }
    struct node *tmp = *head;
    for (int i = 2; i < pos; i++) 
    {
        tmp = tmp->next;
    }
    struct node *delete = tmp->next;
    tmp->next = delete->next;
    free(delete);
}

int main() 
{
    struct node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        insert_at_end(&head, x);
    }
    insert_at_any_pos(&head, 1, 500);
    while (head != NULL) {
        printf("%d ", head->v);
        head = head->next;
    }
    return 0;
}