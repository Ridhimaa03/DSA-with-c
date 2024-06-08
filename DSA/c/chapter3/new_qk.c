#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char a[][15],int l,int u);
void quicksort(char a[][15],int l,int u){
   int i, k,j, pivot, temp;

   if(l<u){
      pivot=l;
      i=l;
      j=u;
      pivot = partition(a,l,u);
      printf("List is divided into sub-lists");
      printf("pivot element is %s",a[pivot]);
      printf("\n List1 is having indices %d to %d ",l,pivot);
      if(l==pivot)
      printf("left sublist is empty");
      else
      printf("list1 is as follow");
      for(k=l;k<pivot;k++)
      {
         printf(" %s",a[k]);
      }
      printf("\n");
      printf("\nList2 is having indices %d to %d and list1 is as follow",pivot+1,u);
      for(k=pivot+1;k<=u;k++)
      {
         printf(" %s",a[k]);
      }
      printf("\n");
      quicksort(a,l,pivot-1);
      quicksort(a,pivot+1,u);

   }

}
int partition(char a[][15],int l,int u){  
   int i, j, pivot;
   char temp[15];

    pivot=l;
    i=l;
    j=u; 

    while(i<j)	{ 
		while((strcmp(a[i],a[pivot])<=0)&&(i<u))
            i++;
   		while((strcmp(a[j],a[pivot])>0))
            j--;
   		if(i<j){
            strcpy(temp,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],temp);
		}
    }

    strcpy(temp,a[pivot]);
    strcpy(a[pivot],a[j]);
    strcpy(a[j],temp);
    return j;
}

int main(){
   int i, n;
   char a[25][15];

   printf("Enter the number of elements you want: ");
   scanf("%d",&n);

   printf("Enter %d elements: ", n);
   for(i=0;i<n;i++)
      scanf("%s",&a[i]);

   quicksort(a,0,n-1);

   printf("Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %s",a[i]);

   return 0;
}
