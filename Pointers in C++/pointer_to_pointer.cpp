#include<iostream>
using namespace std;

int main() {

    int a = 10;
    cout<<"Address of a: "<<&a<<endl;

    int *p = &a;

    cout<<p<<endl;
    cout<<*p<<endl;

    cout<<"Address of p: "<<&p<<endl;

    int **q = &p;

    cout<<q<<endl;
    cout<<*q<<endl; //dereferencing once
    cout<<**q<<endl; //dereferencing twice
    
    cout<<"Address of q: "<<&q<<endl;
    int ***r = &q;

    cout<<r<<endl;
    cout<<*r<<endl;     //dereferencing once
    cout<<**r<<endl;    //dereferencing twice
    cout<<***r<<endl;    //dereferencing thrice

    return 0;
}
