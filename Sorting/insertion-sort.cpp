#include<iostream>
#include "util/inputoutput.h"

void sort(int a[])
{
    int e;
    for(int i=0; i<5; i++) {
        e = a[i];
        int j= i-1;
        while(j>=0 && a[j]>e) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = e;
    }

    for(int i=0 ;i<5; i++) {
        std::cout << a[i] << ",";
    }
    std::cout << "\n";
}

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    std::vector<int> data = getSortInput(argc, argv);

    int arr[5];
    std::cout << "Enter elements in the array:\n";
    for(int i=0; i<5; i++) {
        std::cin >> arr[i];
    }

    sort(arr);
    return 0;
}
