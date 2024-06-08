#include <stdio.h>
int binarySearch(int [], int, int, int);

int main()
{
  int a, l, r,m , n, data, array[100], index;
  

  printf("Enter number of elements: ");
  scanf("%d", &n);

  printf("Enter %d integers: ", n);

  for (a = 0; a < n; a++)
    scanf("%d", &array[a]);

  printf("Enter value to find: ");
  scanf("%d", &data);

  l = 0;
  r = n - 1;
  m = (l + r)/2;

  index = binarySearch(array, l, r, data);


  if (data < index){
            printf("Data is in left side from mid");
            printf("\n");
        }
    else(data > index);{
            printf("Data is in right side from mid");
            printf("\n");
        } 
          
  if (index == -1) 
    printf("Not found! %d isn't present in the list.\n", data);
  else
    printf("%d is present at location %d.\n", data, index + 1);
 
  return 0;
}

int binarySearch(int a[], int l, int r, int data) {
  int m;
 
  if (l > r) // Not found
     return -1;

  m = (l + r)/2;

  if (a[m] == data)  // element found
    return m;
  else if (data > a[m])  
    return binarySearch(a, m+1, r, data);
  else
    return binarySearch(a, l, m-1, data);

    
}