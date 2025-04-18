#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int v;
    struct Node *left,*right;
};

struct Node *newnode(int v)
{
    struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
    nw->v = v;
    nw->left = nw->right = NULL;
    return nw;
}

struct Node *insert(struct Node *root,int v)
{
    if(root == NULL) return newnode(v);
    if(v > root->v)
        root->right = insert(root->right,v);
    else if(v < root->v)
        root->left = insert(root->left,v);
    return root;        
}

void inorder(struct Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->v);
    inorder(root->right);   
}

struct Node *search(struct Node *root,int v)
{
    if(root == NULL || root->v == v)
        return root;
    if(v > root->v)
        return search(root->right,v);
    else return search(root->left,v);
} 

struct Node *minValueNode(struct Node *node) 
{
    while(node->left != NULL)
        node = node->left;
    return node;
}

struct Node *deleteNode(struct Node *root, int v) 
{
    if(root == NULL) return root;
    
    if(v < root->v)
        root->left = deleteNode(root->left, v);
    else if(v > root->v)
        root->right = deleteNode(root->right, v);
    else 
    {
        //jodi sudhumatro right child thake:
        if(root->left == NULL) 
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        //jodi syudhumatro left child thake
        else if(root->right == NULL) 
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        //jodi 2ta chuild e thake:
        struct Node *temp = minValueNode(root->right);
        root->v = temp->v;
        root->right = deleteNode(root->right, temp->v);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        root = insert(root,x);
    }
    inorder(root);
    int f;
    scanf("%d",&f);
    if(search(root,f) == NULL)
        printf("\nValue Not find\n");
    else
    printf("\nValue find\n");   
    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);
    if(search(root, value) == NULL)
        printf("Value %d not found in the BST!", value);
    else 
    {
        root = deleteNode(root, value);
    }
    inorder(root);
}
