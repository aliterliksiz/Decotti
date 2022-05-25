#include <math.h>
#include <stdio.h>
#include <time.h>
 

void insertionSort(int arr[], int n)
{
    int i, key, j;
    int adim=0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            adim++;
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Adim sayisi = %d\n",adim);
}
 

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    clock_t t;
    t=clock();
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr2[] = {10,9,8,7,6,5,4,3,2,1};
    int m = sizeof(arr2)/sizeof(arr2[0]);

    int arr3[] = {3,7,5,10,1,9,6,2,8,4};
    int p = sizeof(arr3)/sizeof(arr3[0]); 
 
    insertionSort(arr, n);
    printArray(arr, n);

    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Took %f mseconds to execute \n", time_taken);

    insertionSort(arr2, m);
    printArray(arr2, m);

    t=clock()-t;
    double time_takenn = ((double)t)/CLOCKS_PER_SEC; 
    printf("Took %f mseconds to execute \n", time_takenn);

    insertionSort(arr3, p);
    printArray(arr3, p);

    t=clock()-t;
    double time_takennn = ((double)t)/CLOCKS_PER_SEC; 
    printf("Took %f mseconds to execute \n", time_takennn);
 
    return 0;
}