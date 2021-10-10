#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_INSERTIONSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_INSERTIONSORT_H

#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

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

}

#endif

