#include<iostream>
using namespace std;

int main() {

    int a = 10;
    int *aptr = 0;
    cout<<aptr<<endl; // Prints value assigned to aptr

    aptr = &a;  //referencing the pointer

    // Prints the address of a
    cout<<&a<<endl;
    cout<<aptr<<endl;

    // Prints the value of a
    cout<<a<<endl;
    cout<<*aptr<<endl; // dereferencing the pointer

    // Prints the address of pointer aptr
    cout<<&aptr<<endl;

    *aptr += 20;
    cout<<a<<endl;
    cout<<*aptr<<endl;

    // Pointer increment and decrement
    aptr++;
    cout<<aptr<<endl;

    aptr -= 4;
    cout<<aptr<<endl;

    char ch = 'a';
    char *cptr = &ch;
    cout<<cptr<<endl;

    cptr --;
    cout<<cptr<<endl;


    return 0;
}