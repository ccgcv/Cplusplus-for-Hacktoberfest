#include <iostream>
#include <utility>
#include "util/inputoutput.h"

// Function sort the array using Cycle sort
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on the right place
    for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++) {

        // initialize item as starting point
        int item = arr[cycleStart];

        // Find position where we put the item. We basically
        // Count all smaller elements on right side of item.
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // If item is already in correct position simply continue
        if (pos == cycleStart) {
            continue;
        }

        // ignore all duplicate  elements since we they are "sorted"
        while (item == arr[pos]) {
            pos += 1;
        }

        // move the item to it's right position
        if (pos != cycleStart) {
            std::swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycleStart) {
            pos = cycleStart;

            // Find position where we put the element
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos += 1;
                }
            }

            // Ignore all duplicate  elements
            while (item == arr[pos]) {
                pos += 1;
            }

            // Put the item to it's right position
            if (item != arr[pos]) {
                std::swap(item, arr[pos]);
                writes++;
            }
        }
    }
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    std::vector<int> arr = getSortInput(argc, argv);
    int n = arr.size();

    printArray(&arr[0], n);
    cycleSort(&arr[0], n);

    std::cout << "\n"
              << "After sort : " << "\n";
    printArray(&arr[0], n);

    return 0;
}
