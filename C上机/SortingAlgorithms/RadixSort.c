#include <stdio.h>
#include <stdlib.h>
#include "RadixSort.h"


/* Driver program to test insertion sort */
// Driver Code
int main() 
{ 
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is n\n");
    PrintArray(arr, n);

    RadixSort(arr,n);
    printf("Sorted array: \n"); 
    PrintArray(arr, n); 
    return 0; 
}