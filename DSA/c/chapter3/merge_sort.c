#include<stdio.h>
 
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
    int a[30],n,i;
    printf("Enter no of elements you want:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("Sorted array is :");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
 
void mergesort(int a[],int l,int u)
{
    int k,mid;
    if(l<u)
    {
        mid=(l+u)/2;
        
        printf("List is divided into sub-lists");
	    printf("\n List1 is having indices %d to %d ",l,mid);
        printf("list1 is as follow");
        for(k=l;k<mid+1;k++)
        {
            printf(" %d",a[k]);
        }
        printf("\n");
        printf("\nList2 is having indices %d to %d and list1 is as follow",mid+1,u);
        for(k=mid+1;k<=u;k++)
        {
            printf(" %d",a[k]);
        }
        printf("\n");
        
        mergesort(a,l,mid); //left recursion
        mergesort(a,mid+1,u); //right recursion
        merge(a,l,mid,mid+1,u); //merging of two sorted sub-arrays
        }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    //second array used for merging
    int b[50]; 
    int i,j,k;
    i=i1; //beginning of the first list
    j=i2; //beginning of the second list
    k=0;
    while(i<=j1 && j<=j2) //while elements in both lists
    {
        if(a[i]<a[j]){
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }
    }
    //copy remaining elements of the first list
    while(i<=j1)
    b[k++]=a[i++];
     //copy remaining elements of the second list
    while(j<=j2)
    b[k++]=a[j++];
    //Transfer elements from b[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=b[j];
}
