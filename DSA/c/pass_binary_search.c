#include <stdio.h>
int binarySearch(int [], int, int, int);

int main()
{
  int a, l, r, n, data, array[100], index;

  printf("----------Binary Search----------");
    printf("\n");

  printf("Enter number of elements: ");
  scanf("%d", &n);

  printf("Enter %d sorted integers: ", n);

  for (a = 0; a < n; a++)
    scanf("%d", &array[a]);

  printf("Enter value to find: ");
  scanf("%d", &data);

  l = 0;
  r = n - 1;

  index = binarySearch(array, l, r, data);
 
  if (index == -1)
    printf("Not found! %d isn't present in the list.\n", data);
  else
    printf("%d is present at index %d.\n", data, index );
 
  return 0;
}

int binarySearch(int a[], int l, int r, int data) {
  int m,i;
  printf("list with lower bound %d upper bound %d is:",l,r);
      for (i = l; i<=r; i++)
        {
            printf(" %d",a[i]);
          
        }
        printf(" \n");
  if (l > r) // Not found
     return -1;

  m = (l + r)/2;

  if (a[m] == data)  // element found
    return m;
  else if (data > a[m])  
  { printf("searchiing in right sublist");
    return binarySearch(a, m+1, r, data);
  }
  else
    { printf("searchiing in left sublist");
    return binarySearch(a, l, m-1, data);
    }
}