#include <stdio.h>
#include <conio.h>
int main(){
    
    int arr[100],n,i,j,min,t;
    printf("Number of elements, you want:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (i = 0; i<n; i++)
    scanf("%d",&arr[i]);
    
    for (i = 0; i<n-1; i++)
    {
       printf(" pass %d elements : ",i);
        for(j=0; j<n;j++)
        {printf(" %d ",arr[j]);}
        printf("\n");
        min=i;
        for(j=i+1; j<n;j++)
        {
            if(arr[j]<arr[min])
            {
               min=j;
            }
            
        }
       if (min != i){
            t = arr[i];
            arr[i]= arr[min];
            arr[min]=t;
       }
         
    }
    printf("Sorted array: ");
    for (i = 0; i<n; i++){
        printf(" %d",arr[i]);   
    }
}