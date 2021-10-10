//counting sort in c++

#include <iostream>
#include <vector>

void countingSort(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0;i<n;i++) {
        if (arr[i]>largest) {
            largest = arr[i];
        }
    }

    std::vector<int> freq(largest+1,0);
    for (int i=0;i<n;i++) {
        freq[arr[i]]++;
    }

    int j = 0;
    for (int i=0;i<=largest;i++) {
        while(freq[i]>0) {
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }

    //printing the array
    for (int i=0;i<n;i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << "\n";
}

int main()
{
    int size;
    std::cout << "Enter size of array:\n";
    std::cin >> size;
    int arr[size];

    for (int i = 0;i<size;i++) {
        std::cout << "Enter " << i+1 << " element of array:\n";
        std::cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(int);
    countingSort(arr, n);
    return 0;;
}
