#include <stdio.h>
#include <conio.h>
int main(){
    printf("----------Lets Sort An Array with Insertion Sort----------");
    printf("\n");

    //declaring some variables that are needed
    int a[100],n,i,j,k,temp;
    printf("Number of elements, you want to be sorted:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (i = 0; i<n; i++)
    scanf("%d",&a[i]);
    // Outer loop for unsorted elements
    for (i = 1; i<n; i++)
    {
        printf("after pass %d the sorted  list is: ",i);
        for (k = 0; k<n; k++){
            printf(" %d",a[k]);
        }
        printf("\n");
        
        temp=a[i];
        j=i-1;
        // for sorted elements
        while(j>=0 && a[j]>temp)
        {
            
            
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        
        }
        //Printing Result
        printf("Sorted array: ");
        for (i = 0; i<n; i++){
            printf(" %d",a[i]);
        }
}