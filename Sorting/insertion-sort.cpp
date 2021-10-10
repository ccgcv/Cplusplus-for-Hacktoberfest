#include<iostream>

using namespace std;

void sort(int a[])
{
    int e;
    for(int i=0; i<5; i++) {
        e = a[i];
        int j= i-1;
        while(j>=0 && a[j]>e) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = e;
    }

    for(int i=0 ;i<5; i++) {
        cout<<a[i]<<",";
    }
}

int main()
{
    int arr[5];
    cout<<"Enter elements in the array:";
    for(int i=0; i<5; i++) {
        cin>>arr[i];
    }

    sort(arr);
    return 0;
}
