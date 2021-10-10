/* This Sorting Algorith is based on array index matching, if element matches with the index number then that element is assigned at that place or index of array */
/* if we will assign each element at unique index and then print array in increasing order, ofcorse element will be printed in ascending order*/

#include "util/inputoutput.h"

void AnandSort(int* B, int n)
{
    int i,j,A[100]={0};   // Initally each index is assigned with 0

    for(i=0;i<n;i++) {
        for(j=0;j<=100;j++) {
            if(B[i]==j) {
                ++A[j];
                break;
            }
        }
    }
    int dst = 0;
    for(i=0;i<100;i++) {
        while ( A[i]!=0 ) {      //It will print only that index element value which is not having 0 
            B[dst] = i;
            ++dst;
            --A[i];
        }
    }
}

int main(int argc, char* argv[])
{
    using ccgcv::Hacktoberfest::Sort::Util::getSortInput;
    using ccgcv::Hacktoberfest::Sort::Util::displayResult;

    std::vector<int> B = getSortInput(argc, argv);
    int n = B.size();

    AnandSort(&B[0], B.size());
    displayResult(B);
    return 0;
}
