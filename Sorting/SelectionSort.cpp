#include<iostream>
#include "util/inputoutput.h"

void SelectionSort(int* a, int* aEnd)
{
    int size = aEnd - a;
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

