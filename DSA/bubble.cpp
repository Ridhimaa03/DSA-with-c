#include<iostream>
using namespace std;

int main(){
    printf("----------Lets Sort An Array with Bubble Sort----------");
    printf("\n");
    //declaring some variables that are needed
    int arr[100],n,i,j,t;
    // variable, which will be using to get out from loop when needed 
    int f=0;
    printf("Number of elements, you want to be sorted:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (i = 0; i<n; i++)
    scanf("%d",&arr[i]);
    // Outer loop for passes
    for (i = 0; i<n-1; i++)
    {
        printf("In pass %d elements are sorted as: ",i);
        for(j=0; j<n;j++)
        {printf(" %d ",arr[j]);}
        printf("\n");
        
        // For inner iterations
        for(j=0; j<n-1-i;j++)
        {
            
            
            //Condition for comperision
            if(arr[j]>arr[j+1])
            {
                //Swapping 
                t = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=t;
                f=1;
            }        }
        // To avoid the not needed passes
        if(f==0){
            break;
        }
            
    }
    //Printing Result
    //Printing Result
    printf("Sorted array: ");
    for (i = 0; i<n; i++){
        printf(" %d",arr[i]);   
    }
}