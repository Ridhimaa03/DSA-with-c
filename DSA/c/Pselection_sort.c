#include <stdio.h>
#include <conio.h>
int main(){
    printf("----------Lets Sort An Array With SELECTION SORT----------");
    printf("\n");
    //declaring some variables that are needed
    int arr[100],n,i,j,min,t;
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
        min=i;
        // For inner iterations
        for(j=i+1; j<n;j++)
        {
            //Condition for comperision
            if(arr[j]<arr[min])
            {
               min=j;
            }
            
        }
       if (min != i){
           //Swapping 
            t = arr[i];
            arr[i]= arr[min];
            arr[min]=t;
       }
         
    }
    //Printing Result
    printf("Sorted array: ");
    for (i = 0; i<n; i++){
        printf(" %d",arr[i]);   
    }
}