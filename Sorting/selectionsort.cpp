#include<iostream>
#include "util/inputoutput.h"

void sort(int a[], int size)
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

    for(int i=0; i<size; i++) {
       std::cout << a[i] << ",";
    }
    std::cout << "\n";
}


int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    std::vector<int> arr = getSortInput(argc, argv);

   sort(&arr[0], arr.size());

}
