#include<iostream>
#include "util/inputoutput.h"

void sort(int a[], int size)
{
    int e;
    for(int i=0; i<size; i++) {
        e = a[i];
        int j= i-1;
        while(j>=0 && a[j]>e) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = e;
    }

    for(int i=0 ;i<size; i++) {
        std::cout << a[i] << ",";
    }
    std::cout << "\n";
}

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    std::vector<int> arr = getSortInput(argc, argv);

    sort(&arr[0], arr.size());
    return 0;
}
