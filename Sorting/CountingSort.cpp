//counting sort in c++

#include <vector>
#include "util/inputoutput.h"

void CountingSort(int* arr, int* arrEnd)
{
    int n = arrEnd - arr;
    int largest = arr[0];
    for (int i = 0;i<n;i++) {
        if (arr[i]>largest) {
            largest = arr[i];
        }
    }

    std::vector<int> freq(largest+1,0);
    for (int i=0;i<n;i++) {
        freq[arr[i]]++;
    }

    int j = 0;
    for (int i=0;i<=largest;i++) {
        while(freq[i]>0) {
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }
}

