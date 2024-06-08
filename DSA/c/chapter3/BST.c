#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if(root == NULL)
        return getNewNode(val);

    if(root->data < val)
        root->right = insert(root->right,val);
    
    else if(root->data > val)
        root->left = insert(root->left,val);
  
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void preorder(struct node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // node with minimum value will have no left child
        return find_minimum(root->left); // left most element will be minimum
    return root;
}

// funnction to delete a node
struct node* delete(struct node *root, int val)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (val>root->data)
        root->right = delete(root->right, val);
    else if(val<root->data)
        root->left = delete(root->left, val);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}



int main()
{
    int n,a[50],i,j;
    struct node *root = NULL;
    printf("Enter the no. of elements you want to add: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {root = insert(root,a[i]);}    
    
    printf("inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("postorder traversal: ");
    postorder(root);
    printf("\n");
    printf("Enter the elements you want to delete: ");
    scanf("%d",&j);
    for(i=0;i<n;i++)
    root=delete(root, j);
    printf("inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("postorder traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}