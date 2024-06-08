#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int roll;
    char *name;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val1,int val2,char *val3)
{
    int i,str,n;
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data   = val1;
    newNode->roll   = val2;
    newNode->name = val3;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val1,int val2,char *val3)
{
    if(root == NULL)
        return getNewNode(val1,val2,val3);

    if(root->data < val1)
        root->right = insert(root->right,val1,val2,val3);
    
    else if(root->data > val1)
        root->left = insert(root->left,val1,val2,val3);
  
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
     printf("%d (%d) (%s)",root->data,root->roll,root->name);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d (%d) (%s)",root->data,root->roll,root->name);
}
void preorder(struct node *root)
{
    if(root == NULL)
        return;
    printf("%d (%d) (%s)",root->data,root->roll,root->name);
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
            root->roll = temp->roll;
            root->name = temp->name;
            root->right = delete(root->right, temp->data);
        }
    }
    
    
    return root;
}



int main()
{
    int n,a[50],i,r[50];
    char name[50][10];
    struct node *root = NULL;
    printf("Enter the no. of total no. of students: ");
    scanf("%d",&n);
    printf("Enter the Roll Number: ");
    for(i=0;i<n;i++)
    scanf("%d",&r[i]);
    printf("Enter the attendance: ");

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the names: ");
    for(i=0; i<n; i++)
    scanf("%s",name[i]);
    for(i=0;i<n;i++)
    {root = insert(root,a[i],r[i],name[i]);}    


    printf("inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("postorder traversal: ");
    postorder(root);
    printf("\n");
    
    


    for(i=0;i<n;i++)
    {
      printf("Roll Number %d has %d percent attendance and her name is %s ",r[i],a[i],name[i]);
      printf("\n");
    }
    printf("-------------------------------------------");
    printf("\n");

    for (i = 0; i < n; i++)
    {
        int x=50,x1=75;
        if(a[i]>x && a[i]<x1)
        {
            
            int y=a[i];
            root=delete(root, y);
            printf("\n");
            printf("-----------After deletion--------\n");
            printf("Element to be deleted %d",y);
            printf("\n");
            printf("inorder traversal: ");
            inorder(root);
            printf("\n");
            printf("preorder traversal: ");
            preorder(root);
            printf("\n");
            printf("postorder traversal: ");
            postorder(root);
            printf("\n");
        }
    }

    printf("----------THANK YOU----------");
    
    return 0;
}
