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
    ValueType pivot = *pivotPoint; // Selecting last element as pivot element
    I index_p = begin;
    for(I loop = begin; loop != pivotPoint; ++loop) {
        if(*loop < pivot) {  // If a[i] is less than pivot element then swap the elements
            ValueType temp=*index_p;
            *index_p=*loop;
            *loop=temp;
            index_p++;
        }
    }
    // Put pivot element in the index_p

    ValueType temp = *index_p;
    *index_p=*pivotPoint;
    *pivotPoint=temp;
    return index_p; // Return the index of pivot element
}

// Function to sort the array after partitioning using recursion
std::string indent;
template<typename I>
void QuickSort(I init, I begin, I end)
{
    if (std::distance(begin, end) > 1) {
        I p;
        p = partition(begin, end);
        QuickSort(init, begin ,p);    // Sort all elements from start to pivot(excluding)
        QuickSort(init, p + 1, end);      // Sort all elements after pivot to end
    }
}
template<typename I>
void QuickSort(I begin, I end)
{
    QuickSort(begin, begin, end);
}
}

#endif

