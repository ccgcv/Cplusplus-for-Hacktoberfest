#include<iostream>
using namespace std;



int main() {

    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    int k;
    cout<<"Enter number to search: ";
    cin>>k;

    search(n, arr, k);

    return 0;
}
