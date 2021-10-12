#include "util/inputoutput.h"

void InsertionSort(int* a, int* aEnd)
{
    int size = aEnd - a;
    int e;
    for(int i=0; i<size; i++) {
        e = a[i];
        int j= i-1;
        while(j>=0 && a[j]>e) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = e;
    }
}

