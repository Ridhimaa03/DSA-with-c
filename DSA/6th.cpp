#include<iostream>
using namespace std;

struct node
{
    char usn[25],name[25],branch[25];
    int sem;
    long int phone;
    struct node *link;
};
typedef struct node * NODE;

NODE start = NULL;
int count=0;


NODE create()
{
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));

    if(snode == NULL)
    {
        cout<<"\nMemory is not available";
        exit(1);
    }
    cout<<"\nEnter the usn,Name,Branch, sem,PhoneNo of the student:";
    scanf("%s %s %s %d %ld",snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link=NULL;
    count++;
    return snode;
}

NODE insertfront()
{
    NODE temp;
    temp = create();
    if(start == NULL)
    {
           return temp;
    }

    temp->link = start;
    return temp;
}


NODE deletefront()
{
    NODE temp;
    if(start == NULL)
    {
        cout<<"\nLinked list is empty";
        return NULL;
    }

    if(start->link == NULL)
    {
            cout<<"\nThe Student node with usn:%s is deleted ",start->usn;
            count--;
            free(start);
            return NULL;
    }
    temp = start;
    start = start->link;
    cout<<"\nThe Student node with usn:%s is deleted",temp->usn;
    count--;
    free(temp);
    return start;
}

NODE insertend()
{
    NODE cur,temp;
    temp = create();

    if(start == NULL)
    {
      return temp;
    }
    cur = start;
    while(cur->link !=NULL)
    {
         cur = cur->link;
    }
    cur->link = temp;
    return start;
}

NODE deleteend()
{
     NODE cur,prev;
     if(start == NULL)
     {
        cout<<"\nLinked List is empty";
        return NULL;
     }

     if(start->link == NULL)
     {
        cout<<"\nThe student node with the usn:%s is deleted",start->usn;
        free(start);
        count--;
        return NULL;
     }

     prev = NULL;
     cur = start;
     while(cur->link!=NULL)
     {
         prev = cur;
         cur = cur->link;
     }

      cout<<"\nThe student node with the usn:%s is deleted",cur->usn;
      free(cur);
      prev->link = NULL;
      count--;
      return start;
}

void display()
{
    NODE cur;
    int num=1;


    if(start == NULL)
    {

        cout<<"\nNo Contents to display in SLL \n";
        return;
    }
    cout<<"\nThe contents of SLL: \n";
    cur = start;
    while(cur!=NULL)
    {
       cout<<num<<" USN:"<<cur->usn<<"| Name:"<<cur->name<<"| Branch:"<<cur->branch<<"| Sem:"<<cur->sem<<" Ph:"<<cur->phone<<"|";
       cout<<endl;
       cur = cur->link;
       num++;
    }
    cout<<"\n No of student nodes is: \n"<<count;
}

void stackdemo()
{
   int ch;
   while(1)
   {
     cout<<"\n~~~Stack Demo using SLL~~~\n";
     cout<<"\n1:Push operation \n2: Pop operation \n3: Display \n4:Exit \n";
     cout<<"\nEnter your choice for stack demo";
     scanf("%d",&ch);

     switch(ch)
     {
        case 1: start = insertfront();
                break;
        case 2: start = deletefront();
                break;
        case 3: display();
               break;
       default : return;
     }
   }
   return;
}

int main()
{
    int ch,i,n;
    while(1)
    {
        cout<<"\n~~~Menu~~~";
        cout<<"\nEnter your choice for SLL operation \n";
        cout<<"\n1:Create SLL of Student Nodes";
        cout<<"\n2:DisplayStatus";
        cout<<"\n3:InsertAtEnd";
        cout<<"\n4:DeleteAtEnd";
        cout<<"\n5:Stack Demo using SLL(Insertion and Deletion at Front)";
        cout<<"\n6:Exit \n";
        cout<<"\nEnter your choice:";
        scanf("%d",&ch);

        switch(ch)
        {
        case 1 : cout<<"\nEnter the no of students:    ";
                 scanf("%d",&n);
                 for(i=1;i<=n;i++)
                    start = insertfront();
                 break;

        case 2: display();
                break;

        case 3: start = insertend();
                break;

        case 4: start = deleteend();
                break;

        case 5: stackdemo();
                break;

        case 6: exit(0);

        default: cout<<"\nPlease enter the valid choice";

        }
    }
}