#include<iostream>
using namespace std;

int count_1s(int n) {
    int count=0;
    while(n>0) {
        n = n & (n-1);
        count++;
    }
    return count;
}

int main() {

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Number of 1s = "<<count_1s(n)<<endl;

    return 0;
}
