#include <stdio.h>
#include <conio.h>
int binarySearch(int a[100], int l, int r, int data){
    int i,n,mid;
    printf("Number of elements:");
    scanf("%d",&n);
    printf("Enter of the elements in sortes order:");
    for (i = 0; i<n; i++)
    scanf("%d",&a[i]);
    printf("Element to search: ");
    scanf ("%d", &data);
    while (l<=r)
    {
        if (l){
            printf("Data is in right side");
            printf("\n");
        }
        if(r){
            printf("Data is in left side");
            printf("\n");
        }
        l=0;
        r=n-1;
        mid=(l+r)/2;
        if (a[mid]==data){
            return mid;
        }
        if (a[mid]>data){
            r= mid-1;
        }
        else{
            l=mid+1;
        }
        return -1;
    }
    printf("%d found: %d",data, mid);

}
int main(void){
    int a[100],i, l, n, r, mid, data;
    int found_index = binarySearch(a, 0, n-1, data);
       if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;

}