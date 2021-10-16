#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_QUICKSORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_QUICKSORT_H

#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

// Function to partition the array passing array, starting element and last element as parameters
template<typename I>
I partition(I begin, I end)
{
    using ValueType = typename std::iterator_traits<I>::value_type;

    I         pivotPoint = end - 1;
    ValueType pivot = std::move(*pivotPoint); // Selecting last element as pivot element
    I index_p = begin;
    for(I loop = begin; loop != pivotPoint; ++loop) {
        if(*loop < pivot) {  // If a[i] is less than pivot element then swap the elements
            std::iter_swap(index_p, loop);
            ++index_p;
        }
    }
    // Put pivot element in the index_p

    *pivotPoint = std::move(*index_p);
    *index_p    = std::move(pivot);
    return index_p; // Return the index of pivot element
}

// Function to sort the array after partitioning using recursion
template<typename I>
void QuickSort(I begin, I end)
{
    if (std::distance(begin, end) > 1) {
        I p = partition(begin, end);
        QuickSort(begin ,p);    // Sort all elements from start to pivot(excluding)
        QuickSort(p + 1, end);      // Sort all elements after pivot to end
    }
}

}

#endif

