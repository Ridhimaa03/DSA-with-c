#include <iostream>
using namespace std;
#define MAX 5

int stack[MAX],item;
int ch, top=-1, status=0;

void display(){
    cout<<"--------Display--------"<<endl;
    int i;
    if(top==-1){
        cout<<"Stack is empty!!"<<endl;
    }
    else{
        cout<<"Stack elements are"<<endl;
        for(i=top; i>=0; i--){
        cout<<" "<<stack[i]<<endl;
        }
        
    }
    
}

void push(){
    cout<<"--------Push--------"<<endl;
    if(top==4){
        cout<<"Stack Overflow!!"<<endl;
    }
    else{
        cout<<"Enter the element you want to inseart: ";
        cin>>stack[++top];
        cout<<endl;
    }
    display();
}

void pop(){
    cout<<"--------Pop--------"<<endl;
    if(top==-1){
        cout<<"Stack Underflow!!"<<endl;
    }
    else{
        cout<<"Enter the element to remove: ";
        cin>>stack[top--];
        cout<<endl;
    }
    display();
}

void palindrome()
{
    cout<<"--------Palindrome--------"<<endl;
    int flag=1,i;
    printf("\nStack content are:\n");
    for(i=top; i>=0 ; i--){
        printf("| %d |\n", stack[i]);
    }
    printf("\nReverse of stack content are:\n");
    for(i=0; i<=top; i++)
        printf("| %d |\n", stack[i]);

    for(i=0; i<=top/2; i++)
    {
        if( stack[i] != stack[top-i] ){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        printf("\nIt is palindrome number");
        cout<<endl;
    }
    else
    {
        printf("\nIt is not a palindrome number");
        cout<<endl;
    }
}


int main(){
    int choice;
    cout<<"-------------------Menu-------------------"<<endl;
    cout<<"1. PUSH "<<endl;
    cout<<"2. POP"<<endl;
    cout<<"3. PALINDROME "<<endl;
    cout<<"4. DISPLAY "<<endl;
    cout<<"5. Exit"<<endl;
    m:
    cout<<"------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
    case 1:
    push();
        break;
    case 2:
    pop();
        break;
    case 3:
    palindrome();
        break;
    case 4:
    display();
        break;
    default:
        break;
    }
    goto m;
}