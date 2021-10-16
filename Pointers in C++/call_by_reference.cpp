#include<iostream>
using namespace std;

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b=temp;
}

int main() {

    int a = 5;
    int b = 10;

    // // Creating pointers for a and b and passing it to function
    // int *aptr = &a;
    // int *bptr = &b;

    // swap(aptr,bptr);

    // Passing the address of a and b to the function
    swap(&a, &b);

    cout<<"a = "<<a<<" and b = "<<b<<endl;

    return 0;
}
