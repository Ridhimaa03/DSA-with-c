#include<stdio.h>
#include <stdlib.h>
#include <string.h>

 
void mergesort(char a[][100],int i,int j);
void merge(char a[][100],int i1,int j1,int i2,int j2);
 
int main()
{
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d",&n);
    int i;
    char a[15][100];
    printf("Enter the string array: ");
    for(i=0;i<n;i++)
      scanf("%s",&a[i]);
    mergesort(a,0,n-1);
    printf("Sorted string array: ");
    for(i=0;i<n;i++)
      printf("%s ",a[i]);
}
 
void mergesort(char a[][100],int l,int u)
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
	     printf(" %s",a[k]);
	  }
	  printf("\n");
	 printf("\nList2 is having indices %d to %d and list1 is as follow",mid+1,u);
	  for(k=mid+1;k<=u;k++)
	  {
	     printf(" %s",a[k]);
	  }
	  printf("\n");
        mergesort(a,l,mid); //left recursion
        mergesort(a,mid+1,u); //right recursion
        merge(a,l,mid,mid+1,u); //merging of two sorted sub-arrays
        }
}
 
void merge(char a[][100],int i1,int j1,int i2,int j2)
{
    //second array used for merging
    char b[j2+1][100]; 
    int i,j,k;
    i=i1; //beginning of the first list
    j=i2; //beginning of the second list
    k=0;
    while(i<=j1 && j<=j2) //while elements in both lists
    {
        if(strcmp(a[i],a[j])<0){
            strcpy(b[k],a[i]);
            k++;
            i++;
        }
        else{
            strcpy(b[k],a[j]);
            k++;
            j++;
        }
    }
    //copy remaining elements of the first list
    while(i<=j1){
        strcpy(b[k],a[i]);
        i++;
        k++;
    }
    
     //copy remaining elements of the second list
    while(j<=j2){
        strcpy(b[k],a[j]);
        j++;
        k++;
    }
    //Transfer elements from b[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
    strcpy(a[i],b[j]);
}
