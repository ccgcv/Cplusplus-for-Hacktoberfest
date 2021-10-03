#include<iostream>
using namespace std;

void decreasing(int n) {
    if(n==0) 
        return;
    cout<<n<<" ";
    decreasing(n-1);
}

void increasing(int n) {
    if(n==0)
        return;
    increasing(n-1);
    cout<<n<<" ";
}


int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Increasing order: "<<endl;
    increasing(n);

    cout<<endl; 

    cout<<"Decreasing order: "<<endl;
    decreasing(n);

    return 0;
}