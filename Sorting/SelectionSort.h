#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_SELECTIONSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_SELECTIONSORT_H

#include<iostream>
#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

void SelectionSort(int* a, int* aEnd)
{
    int size = aEnd - a;
    int temp;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

}

#endif

