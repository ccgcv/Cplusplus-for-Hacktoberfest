#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_ANANDSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_ANANDSORT_H

/* This Sorting Algorith is based on array index matching, if element matches with the index number then that element is assigned at that place or index of array */
/* if we will assign each element at unique index and then print array in increasing order, ofcorse element will be printed in ascending order*/

#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

template<typename I>
void AnandSort(I begin, I end)
{
    int i,j,A[100]={0};   // Initally each index is assigned with 0

    for(I loop = begin; loop != end; ++loop) {
        for(j=0;j<=100;j++) {
            if(*loop == j) {
                ++A[j];
                break;
            }
        }
    }
    I loop = begin;
    for(i=0;i<100;i++) {
        while ( A[i]!=0 ) {      //It will print only that index element value which is not having 0 
            (*loop) = i;
            ++loop;
            --A[i];
        }
    }
}

}

#endif
