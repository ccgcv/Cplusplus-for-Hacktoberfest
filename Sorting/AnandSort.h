#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_ANANDSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_ANANDSORT_H

/* This Sorting Algorith is based on array index matching, if element matches with the index number then that element is assigned at that place or index of array */
/* if we will assign each element at unique index and then print array in increasing order, ofcorse element will be printed in ascending order*/

#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

void AnandSort(int* B, int* Bend)
{
    int i,j,A[100]={0};   // Initally each index is assigned with 0
    int n = Bend - B;

    for(i=0;i<n;i++) {
        for(j=0;j<=100;j++) {
            if(B[i]==j) {
                ++A[j];
                break;
            }
        }
    }
    int dst = 0;
    for(i=0;i<100;i++) {
        while ( A[i]!=0 ) {      //It will print only that index element value which is not having 0 
            B[dst] = i;
            ++dst;
            --A[i];
        }
    }
}

}

#endif
