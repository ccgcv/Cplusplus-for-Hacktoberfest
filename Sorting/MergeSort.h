#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_MERGESORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_MERGESORT_H

// C++ program for Merge Sort

#include "util/inputoutput.h"
#include <algorithm>
#include <iostream>

namespace ccgcv::Hacktoberfest::Sort
{

// Merges two subarrays of array[].
// First subarray is arr[begin..mid)
// Second subarray is arr[mid..end)

template<typename I>
void merge(I left, I mid, I right)
{
    using ValueType = typename std::iterator_traits<I>::value_type;

    // Create temp arrays
    std::vector<ValueType>    leftArray(std::make_move_iterator(left), std::make_move_iterator(mid));
    std::vector<ValueType>    rightArray(std::make_move_iterator(mid), std::make_move_iterator(right));

    auto indexOfSubArrayOne = std::begin(leftArray); // Initial index of first sub-array
    auto indexOfSubArrayTwo = std::begin(rightArray); // Initial index of second sub-array
    I indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne != std::end(leftArray) && indexOfSubArrayTwo != std::end(rightArray)) {
        if (*indexOfSubArrayOne <= *indexOfSubArrayTwo) {
            std::iter_swap(indexOfMergedArray, indexOfSubArrayOne);
            ++indexOfSubArrayOne;
        }
        else {
            std::iter_swap(indexOfMergedArray, indexOfSubArrayTwo);
            ++indexOfSubArrayTwo;
        }
        ++indexOfMergedArray;
    }

    // Copy the remaining elements of
    // left[], if there are any
    std::move(indexOfSubArrayOne, std::end(leftArray), indexOfMergedArray);
    // Copy the remaining elements of
    // right[], if there are any
    std::move(indexOfSubArrayTwo, std::end(rightArray), indexOfMergedArray);
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
template<typename I>
void MergeSort(I begin, I end)
{
    if (std::distance(begin, end) < 2) {
        return; // Returns recursively
    }

    auto mid = begin + (std::distance(begin, end) / 2);
    MergeSort(begin, mid);
    MergeSort(mid, end);
    merge(begin, mid, end);
}


}

#endif

