#include <iostream>
#include <string>
using namespace std;
int n,i,a[100];
string name[100];
void create(){
    cout<<"--------create--------"<<endl;
    cout<<"Enter number of elements you want to enter: "<<endl;
    cin>>n;
    cout<<"Enter name: "<<endl;
    for(i=0; i<n; i++){
        cin>>name[i];
    }
    cout<<"Enter Roll no: "<<endl;
    for(i=0; i<n; i++){
        cin>>a[i];
    }
}
void display(){
    cout<<"--------Display Info--------"<<endl;
    cout<<"Names of the student are: ";
    for(i=0; i<n; i++){
        cout<<name[i]<<" ";
    }
    cout<<endl;
    cout<<"Roll no. of the student are: ";
    for(i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void inseart(){
    cout<<"--------Inseart Info--------"<<endl;
    int k,e,pos, pos1;
    string nam;
    cout<<"Enter name you want to enter: ";
    cin>>nam;
    cout<<"Enter roll no you want to enter: ";
    cin>>e;
    cout<<"Enter position where you want to enter the element: ";
    cin>>pos;
    for (i = n; i >= pos; i--)
    {
        name[i + 1] = name[i];
        a[i + 1] = a[i];
    }
    name[pos] = nam;
    a[pos] = e;
    n = n + 1;
   
    display();
}

void del(){
    cout<<"--------Delete Info--------"<<endl;
    int pos, e;
    string nam;
    cout<<"Enter the position of the elements to be deleted: ";
    cin>>pos;
    e = a[pos];
    nam = name[pos];
    for (i = pos; i < n; i++)
    {
        a[i] = a[i + 1];
        name[i] = name[i + 1];
    }
    n = n-1;
    cout<<"The deleted name is: "<<nam<<endl;
    cout<<"The deleted roll number is: "<<e<<endl;
    display();
}

int main(){
    int choice;
    cout<<"-------------------Menu-------------------"<<endl;
    cout<<"1. Enter the array elements for N integers"<<endl;
    cout<<"2. Display the array with suitable headings"<<endl;
    cout<<"3. Insert element at given position"<<endl;
    cout<<"4. Delete element from given postion"<<endl;
    cout<<"5. Exit"<<endl;
    m:
    cout<<"------------------------"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
    create();
        break;
    case 2:
    display();
        break;
    case 3:
    inseart();
        break;
    case 4:
    del();
        break;
    default:
        break;
    }
    goto m;
}