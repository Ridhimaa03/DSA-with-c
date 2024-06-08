#include <stdio.h>  
 
void heapify(int a[], int n, int i)  
{
    int k; 
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    
	// If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    
	// If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;
		printf("Swapping is performed at index %d and largest element which is moved to root is: %d \n",i,a[i]);  
        printf("array: ");
		for(k=0;k<n;k++){
		printf("%d ",a[k]);
		}
		printf("\n");
        
        
        heapify(a, n, largest);  
    }  
}  


/*Function to implement the heap sort*/  
void heapSort(int a[], int n)  
{
	//building max heap
	int i;
    for (i = n / 2-1; i >= 0; i--)  
        heapify(a, n, i);  
    
	// Deletion 
    for ( i = n - 1; i >= 0; i--) {  
        //swap top greater value with a[i] 
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
	   
        heapify(a, i, 0);  
    }  
}  


int main()  
{  
    int a[100];
    int i,n;  
    printf("Enter number of elements you want to enter: ");
	scanf("%d",&n);  

    printf("Enter elements: ");
	for (i = 0; i<n; i++)
    scanf("%d",&a[i]);    
    heapSort(a, n);  
    printf("Sorted elements: ");    
    for (i = 0; i<n; i++)
    printf("%d ", a[i]);  
    return 0;  
}  
