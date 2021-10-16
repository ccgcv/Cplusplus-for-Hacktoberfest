#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_SELECTIONSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_SELECTIONSORT_H

#include<iostream>
#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

template<typename I>
void SelectionSort(I begin, I end)
{
    using ValueType = typename std::iterator_traits<I>::value_type;

    for(I loop = begin; loop != end; ++loop) {
        for(I j= loop + 1; j != end; ++j) {
            if(*loop > *j) {
                std::iter_swap(loop, j);
            }
        }
    }
}

}

#endif

