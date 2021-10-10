#include<iostream>
#include "util/inputoutput.h"

void SelectionSort(int a[], int size)
{
    int temp;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    using ccgcv::Hacktoberfest::Sort::Util::displayResult;

    std::vector<int> arr = getSortInput(argc, argv);
    SelectionSort(&arr[0], arr.size());
    displayResult(arr);
}
