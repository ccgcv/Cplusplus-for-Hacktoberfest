#include <iostream>
using namespace std;

// Function sort the array using Cycle sort
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on the right place
    for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++)
    {
        // initialize item as starting point
        int item = arr[cycleStart];

        // Find position where we put the item. We basically
        // Count all smaller elements on right side of item.
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position simply continue
        if (pos == cycleStart)
            continue;

        // ignore all duplicate  elements since we they are "sorted"
        while (item == arr[pos])
            pos += 1;

        // move the item to it's right position
        if (pos != cycleStart)
        {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycleStart)
        {
            pos = cycleStart;

            // Find position where we put the element
            for (int i = cycleStart + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;

            // Ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;

            // Put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr[] = {1, 8, 3, 9, 10, 10, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    cycleSort(arr, n);

    cout << endl
         << "After sort : " << endl;
    printArray(arr, n);
    cout << endl;

    return 0;
}