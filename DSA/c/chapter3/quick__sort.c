#include<stdio.h>
int partition(int a[],int l,int u);
void quicksort(int a[25],int l,int u){
   int i, k,j, pivot, temp;

   if(l<u){
      pivot=l;
      i=l;
      j=u;
      pivot = partition(a,l,u);
      printf("List is divided into sub-lists");
      printf("pivot element is %d",a[pivot]);
      printf("\n List1 is having indices %d to %d ",l,pivot);
      if(l==pivot)
      printf("left sublist is empty");
      else
      printf("list1 is as follow");
      for(k=l;k<pivot;k++)
      {
         printf(" %d",a[k]);
      }
      printf("\n");
      printf("\nList2 is having indices %d to %d and list1 is as follow",pivot+1,u);
      for(k=pivot+1;k<=u;k++)
      {
         printf(" %d",a[k]);
      }
      printf("\n");
      quicksort(a,l,pivot-1);
      quicksort(a,pivot+1,u);

   }

}
int partition(int a[],int l,int u){  
   int i, j, pivot, temp;

    pivot=l;
    i=l;
    j=u; 

    while(i<j){
         while(a[i]<=a[pivot]&&i<u)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      return j;
}

int main(){
   int i, n, a[25];

   printf("Enter the number of elements you want: ");
   scanf("%d",&n);

   printf("Enter %d elements: ", n);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);

   quicksort(a,0,n-1);

   printf("Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",a[i]);

   return 0;
}
