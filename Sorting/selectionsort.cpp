#include<iostream>
#include "util/inputoutput.h"

void sort(int a[])
{
    int temp;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i=0; i<5; i++) {
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

}
