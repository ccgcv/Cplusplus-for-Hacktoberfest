#include<iostream>

using namespace std;

void sort(int a[])
{
    int temp;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i=0; i<5; i++) {
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

}
