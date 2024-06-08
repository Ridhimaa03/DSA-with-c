# include<stdio.h>
 
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], totalp = 0;
   int i, j, u;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
   	
      if (weight[i] > u)
         break;
      else {
      	printf("\nselected object is having %f weight and %f profit",weight[i],profit[i]);
         x[i] = 1.0;
         totalp = totalp + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   totalp = totalp + (x[i] * profit[i]);
   printf("\nLast selected object is having %f weight and %f profit",x[i]*weight[i],x[i]*profit[i]);
 
   printf("\nMaximum profit is:- %f", totalp);
 
}
 
int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
 
   printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }
 
   printf("\nEnter the capacityacity:- ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];ratio[j] = ratio[i];ratio[i] = temp;
 
            temp = weight[j];weight[j] = weight[i];weight[i] = temp;
 
            temp = profit[j];profit[j] = profit[i];profit[i] = temp;
         }
      }
   }
 
   knapsack(num, weight, profit, capacity);
   return(0);
}
