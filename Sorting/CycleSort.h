#ifndef  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_CYCLESORT_H
#define  CCGCV_CPLUSPLUS_FOR_HACKTOBERFEST_SORT_CYCLESORT_H

#include <utility>
#include "util/inputoutput.h"

namespace ccgcv::Hacktoberfest::Sort
{

// Function sort the array using Cycle sort
template<typename I>
void CycleSort(I begin, I end)
{
    using ValueType = typename std::iterator_traits<I>::value_type;
    using std::swap;

    I last = end - 1;
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on the right place
    for (I cycleStart = begin; cycleStart != last; ++cycleStart) {
    //for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++) {

        // initialize item as starting point
        ValueType item = std::move(*cycleStart);

        // Find position where we put the item. We basically
        // Count all smaller elements on right side of item.
        I pos = cycleStart;
        for (I i = cycleStart + 1; i != end; ++i) {
            if (*i < item) {
                ++pos;
            }
        }

        // If item is already in correct position simply continue
        if (pos == cycleStart) {
            continue;
        }

        // ignore all duplicate  elements since we they are "sorted"
        while (item == *pos) {
            ++pos;
        }

        // move the item to it's right position
        if (pos != cycleStart) {
            swap(item, *pos);
            ++writes;
        }

        // Rotate rest of the cycle
        while (pos != cycleStart) {
            pos = cycleStart;

            // Find position where we put the element
            for (I i = cycleStart + 1; i != end; ++i) {
                if (*i < item) {
                    ++pos;
                }
            }

            // Ignore all duplicate  elements
            while (item == *pos) {
                ++pos;
            }

            // Put the item to it's right position
            if (item != *pos) {
                swap(item, *pos);
                ++writes;
            }
        }
    }
}

}

#endif

