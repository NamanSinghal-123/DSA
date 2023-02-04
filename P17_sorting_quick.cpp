
// /* C++  QuickSort using Lomuto's partition Scheme.*/
// #include<bits/stdc++.h>
// using namespace std;
 
// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];    
//     int i = (low - 1);  
 
//     for (int j = low; j <= high- 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;    
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }
 
// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
 
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }
 
// void printArray(int arr[], int size)
// {
//     int i;
//     for (i=0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }
 
// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     quickSort(arr, 0, n-1);
//     printf("Sorted array: \n");
//     printArray(arr, n);
//     return 0;
// }



/* C++  QuickSort using Hoare's partition scheme. */
#include <bits/stdc++.h>
using namespace std;
 
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
 
        do {
            j--;
        } while (arr[j] > pivot);
 
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}