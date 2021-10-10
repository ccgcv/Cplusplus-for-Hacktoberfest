#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_COUNTINGSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_COUNTINGSORT_H

//counting sort in c++

#include <vector>
#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

template<typename I>
void CountingSort(I begin, I end)
{
    int largest = *begin;
    for (I loop = begin; loop != end; ++loop) {
        if ((*loop) > largest) {
            largest = *loop;
        }
    }

    std::vector<int> freq(largest+1, 0);
    for (I loop = begin; loop != end; ++loop) {
        ++freq[*loop];
    }

    I loop = begin;
    for (int i = 0; i <= largest;++i) {
        while(freq[i] > 0) {
            *loop = i;
            --freq[i];
            ++loop;
        }
    }
}

}

#endif

