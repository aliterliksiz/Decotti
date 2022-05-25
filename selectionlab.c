#include <stdio.h>
#include <time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, k, min_idx;

    for ( i = 0; i < n-1; i++)
    {
        min_idx = i;

        for ( j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            
        }
        swap(&arr[min_idx], &arr[i]);
        printArray(arr,20);
    }    
}
void selectionSortRecursive(int arr[], int i, int n)
{
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    swapRecursive(arr, min, i);
    printArray(arr, 20);
    if (i + 1 < n) {
        selectionSortRecursive(arr, i + 1, n);
    }
}
void swapRecursive(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int sz=20;

   int arr[sz],i;

   for(i=0;i<sz;i++)
   {
     arr[i]=rand()%100;
   }
   printf("\nDizinin elemanlari:");
   for(i=0;i<sz;i++)
   {
     printf("%d ",arr[i]);
   }

    printf("\n\n");

    printf("\n\n");

    printf("\n\n RECURSIVE MOOD \n\n");
    selectionSortRecursive(arr,0,20);
    clock_t t2;
    t2 = clock();
    t2 = clock() - t2;
    
    double time_takenm = ((double)t2)/CLOCKS_PER_SEC; 
    printf("Recursive took %f mseconds to execute \n", time_takenm);
    return 0;
}