#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int v;
    struct Node *nxt;
    struct Node *prev;
};

void insert_end(struct Node **head,int v)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->v = v;
    newnode->prev = NULL;
    newnode->nxt = NULL;
    if(!(*head)) 
    {
        *head  = newnode;
        return;
    }
    struct Node *tmp = *head;
    while(tmp->nxt != NULL)
    {
        tmp = tmp->nxt;
    }
    tmp->nxt = newnode;
    newnode->prev = tmp;
}

void print(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->v);
        head = head->nxt;
    }
}

void insert_begin(struct Node **head,int v)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->v = v;
    newnode->prev = NULL;
    newnode->nxt = NULL;
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    (*head)->prev = newnode;
    newnode->nxt = *head;
    *head = newnode;
}

void delete_begin(struct Node **head)
{
    if(*head == NULL)
        return;
    if((*head)->nxt = NULL)
    {
        *head = NULL;
        return;
    }        
    struct Node *tmp = *head;
    *head = (*head)->nxt;
    (*head)->prev = NULL;
    free(tmp);
}

void delete_at_end(struct Node **head)
{
    struct Node *tmp = *head;
    if(*head == NULL)
        return;
    if((*head)->nxt == NULL)
    {
        *head == NULL;
        return;
    }    
    while(tmp->nxt != NULL)
        tmp = tmp->nxt;
    struct Node *last_node = tmp->prev;
    free(tmp);
    last_node->nxt = NULL;
}


void circular(struct Node *head)
{
    struct Node *tmp = head;
    while(tmp->nxt != NULL)
        tmp = tmp->nxt;
    tmp->nxt = head;
    head->prev = tmp;
}


bool circular_chk(struct Node *head)
{
    struct Node *tmp = head;
    while(1)
    {
        if(tmp->nxt == head && head->prev == tmp)
            return true;
        if(tmp->nxt == NULL)
        {
            return false;
            break;
        }    
        tmp = tmp->nxt;
    }
}

bool palindrome(struct Node *head)
{
    struct Node *j = head;
    while(j->nxt != NULL)
        j = j->nxt;
    for(struct Node *i = head;i != j && i->prev != j;i = i->nxt,j = j->prev)
        if(i->v != j->v)
            return false;
    return true;        
}

struct Node* reverse(struct Node *head)
{
    struct Node *j = head;
    while(j->nxt != NULL)
        j = j->nxt;
    for(struct Node *i = head;i != j && i->prev != j;i = i->nxt,j = j->prev)
    {
        int tmp = i->v;
        i->v = j->v;
        j->v = tmp;
    }
    return head;        
}

struct Node* rearrange(struct Node *head) 
{
    if(head == NULL || head->nxt == NULL) 
        return head;
    struct Node *odd = head;
    struct Node *even = head->nxt;
    struct Node *even_head = even;
    while(even != NULL && even->nxt != NULL) 
    {
        odd->nxt = even->nxt;
        odd->nxt->prev = odd;
        odd = odd->nxt;
        
        even->nxt = odd->nxt;
        if(even->nxt != NULL)
            even->nxt->prev = even;
        even = even->nxt;
    }
    odd->nxt = even_head;
    even_head->prev = odd;
    return head;
}

struct Node* swap(struct Node* head) 
{
    if(head == NULL || head->nxt == NULL)
        return head;
    struct Node tmp;
    tmp.nxt = head;
    tmp.prev = NULL;
    head->prev = &tmp;
    struct Node* prev = &tmp;
    while(prev->nxt != NULL && prev->nxt->nxt != NULL)
    {
        struct Node* current = prev->nxt;
        struct Node* nextNode = current->nxt;
        struct Node* nextPair = nextNode->nxt;
        prev->nxt = nextNode;
        nextNode->prev = prev;
        current->nxt = nextPair;
        if(nextPair != NULL) 
            nextPair->prev = current;
        nextNode->nxt = current;
        current->prev = nextNode;
        prev = current;
    }
    head = tmp.nxt;
    head->prev = NULL;
    return head;
}

int main()
{
    struct Node *head = NULL;
    int n; scanf("%d",&n);
    while(n--)
    {
        int x; scanf("%d",&x);
        insert_end(&head,x);
    }
    print(head);
    printf("\n");
    if(palindrome(head)) 
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");   
    head = rearrange(head);
    print(head);
    printf("\n");
    head = swap(head);
    print(head);
    printf("\n");
    insert_begin(&head,350);
    print(head);
    printf("\n");
    delete_begin(&head);
    print(head);
    printf("\n");
    if(circular_chk(head))
        printf("Circular\n");
    else
        printf("Not Circular\n");    
    reverse(head);
    print(head);
    printf("\n");    

}