//counting sort in c++

#include <iostream>
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

    //printing the array
    for (int i=0;i<n;i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << "\n";
}

int main(int argc, char* argv[])
{
std::cout << "1\n";
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    std::vector<int> arr = getSortInput(argc, argv);
    int size = arr.size();
std::cout << "2\n";

    countingSort(&arr[0], size);
std::cout << "3\n";
    return 0;;
}
