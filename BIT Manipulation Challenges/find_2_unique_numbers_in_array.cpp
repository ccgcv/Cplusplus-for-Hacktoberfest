#include<iostream>
using namespace std;

int checkSetBit(int ele, int pos) {
    return ((ele & (1 << pos)) != 0);
}

void unique(int n, int arr[]) {
    int xorSum=0;
    for(int i=0; i<n; i++) {
        xorSum = xorSum ^ arr[i];
    }

    int tempXor = xorSum;

    int setBit=0;
    int pos=-1;
    while(setBit!=1) {
        setBit = xorSum & 1;
        pos++;
        xorSum = xorSum >> 1; //right shift by 1 bit
    }

    int newXor=0;
    for(int i=0; i<n; i++) {
        if((checkSetBit(arr[i], pos)) == 1)
            newXor = newXor ^ arr[i];
    }

    int unique1 = newXor;
    int unique2 = newXor ^ tempXor;

    cout<<"Two unique numbers in the array are "<<unique1<<" and "<<unique2<<endl;
}



int main() {

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++) {
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
    //         if(i!=j && (arr[i]^arr[j])==0)
    //             break;
    //     }
    //     if(j==n)
    //         cout<<arr[i]<<endl;
    // }

    //  METHOD 3
    unique(n, arr);

    return 0;
}