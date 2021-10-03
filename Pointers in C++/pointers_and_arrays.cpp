#include<iostream>
using namespace std;

int main() {

    int array[] = {10, 20, 30};

    cout<<*array<<endl;

    int *ptr=array; // Here arr stores the address of first array element

    for(int i=0; i<3; i++) {
        cout<<*ptr<<endl;
        ptr++;
    }

    // Using array as pointer
    for(int i=0; i<3; i++)
        cout<<*(array+i)<<endl;

    return 0;
}