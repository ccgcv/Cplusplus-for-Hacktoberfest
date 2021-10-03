#include<iostream>
using namespace std;

bool sort(int n, int arr[]) {
    if(n==1)
        return true;
    return ((arr[0]<=arr[1]) && sort(n-1, arr+1));
}

int main() {

    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<n; i++) 
        cin>>arr[i];

    cout<<sort(n, arr);
    

    return 0;
}
