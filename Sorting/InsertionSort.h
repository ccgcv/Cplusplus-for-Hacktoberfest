#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_INSERTIONSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_INSERTIONSORT_H

#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

template<typename I>
void InsertionSort(I begin, I end)
{
    using ValueType = typename std::iterator_traits<I>::value_type;

    ValueType e;
    for (I loop = begin + 1; loop != end; ++loop) {
        e = std::move(*loop);
        I j= loop-1;
        while(j != begin && *j > e) {
            *(j+1) = std::move(*j);
            --j;
        }
        *(j+1) = std::move(e);
    }
}

}

#endif

