#include "util/inputoutput.h"

// Function to partition the array passing array, starting element and last element as parameters
int partition(int a[],int start,int end)
{
    int pivot = a[end]; // Selecting last element as pivot element
    int index_p = start;
    for(int i=start;i<end;i++) {
        if(a[i]<pivot) {  // If a[i] is less than pivot element then swap the elements
            int temp=a[index_p];
            a[index_p]=a[i];
            a[i]=temp;
            index_p++ ;
        }
    }
    // Put pivot element in the index_p

    int temp = a[index_p];
    a[index_p]=a[end];
    a[end]=temp;
    return index_p; // Return the index of pivot element
}

// Function to sort the array after partitioning using recursion
void QuickSort(int a[], int start, int end)
{
    if(start<end) {
        int p;
        p = partition(a,start, end);
        QuickSort(a,start,p-1); // Sort all elements from start to pivot(excluding)
        QuickSort(a,p+1,end); // Sort all elements after pivot to end
    }
}
void QuickSort(int* a, int* aEnd)
{
    QuickSort(a, 0, aEnd - a - 1);
}

