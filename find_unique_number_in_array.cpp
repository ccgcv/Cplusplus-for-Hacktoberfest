#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // //  METHOD 1
    // int j;
    // for(int i=0; i<n; i++) {
    //     for(j=0; j<n; j++) {
    //         if(i!=j && arr[i]==arr[j])
    //             break;
    //     }
    //     if(j==n)
    //         cout<<arr[i]<<endl;
    // }

    // //  METHOD 2
    // int j;
    // for(int i=0; i<n; i++) {
    //     for(j=0; j<n; j++) {
    //         if ((arr[i] ^ arr[j]) == 0  && i!=j)
    //             break;
    //     }
    //     if(j==n)
    //         cout<<arr[i]<<endl;
    // }

    //  METHOD 3 - Efficient Method
    int xorSum = 0;
    for(int i=0; i<n; i++) {
        xorSum = (arr[i] ^ xorSum);
    }
    cout<<xorSum<<endl;


    return 0;
}