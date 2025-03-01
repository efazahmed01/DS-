#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    char data;
    struct Node* next;
};


int isEmpty(struct Node* top) 
{
    return top == NULL;
}


void push(struct Node** top, char data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top) 
{
    if (isEmpty(*top)) return;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
}
int isMatchingPair(char open, char close) 
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


int isBalanced(char *ch) 
{
    struct Node* top = NULL;
    
    for (int i = 0; ch[i] != '\0'; i++) 
    {
        if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[') 
        {
            push(&top, ch[i]);  
        } 
        else if (ch[i] == ')' || ch[i] == '}' || ch[i] == ']') 
        {
            if (isEmpty(top) || !isMatchingPair(top->data, ch[i])) 
            {
                return 0; 
            }
            pop(&top);
        }
    }

    return isEmpty(top); 
}

int main() 
{
    char ch[100]; 
    scanf("%s", ch);

    if(isBalanced(ch)) 
    {
        printf("Balanced\n");
    } 
    else 
    {
        printf("Not Balanced\n");
    }

    return 0;
}
