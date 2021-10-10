/* This Sorting Algorith is based on array index matching, if element matches with the index number then that element is assigned at that place or index of array */
/* if we will assign each element at unique index and then print array in increasing order, ofcorse element will be printed in ascending order*/

#include <iostream>
#include "util/inputoutput.h"

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    std::vector<int> data = getSortInput(argc, argv);

    int i,j,n,A[100]={0};   // Initally each index is assigned with 0
    std::cout << "Enter Size Of the Array:\n";
    std::cin >> n;
    int B[n];
    std::cout << "Enter elements:\n";
    for(i=0;i<n;i++) {
        std::cin >> B[i];
    }
    for(i=0;i<n;i++) {
        for(j=0;j<=100;j++) {
            if(B[i]==j) {
                A[j]=B[i];
                break;
            }
        }
    }
    for(i=0;i<100;i++) {
        if(A[i]!=0) {      //It will print only that index element value which is not having 0 
            std::cout << A[i] << " ";
        }
    }
    std::cout << "\n";
    return 0;
}
