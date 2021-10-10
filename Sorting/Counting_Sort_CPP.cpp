//counting sort in c++

#include <vector>
#include "util/inputoutput.h"

void countingSort(int arr[], int n)
{
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

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    using ccgcv::Hacktoberfest::Sort::Util::displayResult;

    std::vector<int> arr = getSortInput(argc, argv);
    countingSort(&arr[0], arr.size());
    displayResult(arr);

    return 0;;
}
