#include<iostream>
using namespace std;

void powerof2(int n) {
    if (n!=0 && (n&(n-1))==0)
        cout<<n<<" is a power of 2";
    else
        cout<<n<<" is not a power of 2";
}

int main() {

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    powerof2(n);

    return 0;
}
