#include <iostream>
using namespace std;
int n,i,a[100];
void create(){
    
    cout<<"Enter number of elements you want to enter: "<<endl;
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(i=0; i<n; i++){
        cin>>a[i];
    }
}
void display(){
    cout<<"Given array is: ";
    for(i=0; i<n; i++){
        cout<<" "<<a[i]<<endl;
    }
}
void inseart(){
    int e,k,pos;
    cout<<"Enter element you want to enter: ";
    cin>>e;
    cout<<"Enter position where you want to enter the element: ";
    cin>>pos;
    for (i = n; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = e;
    n = n + 1;
    display();
  
}

void del()
{
    int pos, e;
    cout<<"Enter the position of the element to be deleted: ";
    cin>>pos;
    e = a[pos];
    for (i = pos; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n = n-1;
    cout<<"The deleted element is: "<<e<<endl;
    display();    
}

int main(){
    int choice;
    cout<<"1. Enter the array elements for N integers"<<endl;
    cout<<"2. Display the array"<<endl;
    cout<<"3. Insert array at given position"<<endl;
    cout<<"4. Delete array from given postion"<<endl;
    cout<<"5. Exit"<<endl;
    m:
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