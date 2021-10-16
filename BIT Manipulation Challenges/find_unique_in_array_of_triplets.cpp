#include<iostream>
using namespace std;

// //  METHOD 1
// void unique(int n, int arr[]) {
//     int j;
//     for(int i=0; i<n; i++) {
//         for(j=0; j<n; j++) {
//             if (i!=j && arr[i]==arr[j])
//                 break;                    
//         }
//         if(j==n)
//             cout<<arr[i]<<endl;
//     }
// }


//  METHOD 2
bool getBit(int ele, int pos) {
    return ((ele & (1<<pos)) != 0);
}

int setBit(int ele, int pos) {
    return (ele | (1<<pos));
}

int unique(int n, int arr[]) {
    int result=0;
    for(int i=0; i<64; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            if(getBit(arr[j], i))
                count++;
        }
        if(count%3 != 0)
            result = setBit(result, i);
    }
    return result;
}



int main() {

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++) 
        cin>>arr[i];

    cout<<"Unique element is "<<unique(n, arr);

    return 0;
    
}