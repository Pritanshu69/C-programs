#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
        cout<<endl;
    }
}

int main() {
    int n;

    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}