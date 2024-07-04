#include <iostream>
using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high];
    
    // Index of the smaller element
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            // Swap arr[i+1] and arr[j]
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] to place the pivot in its correct position
    swap(arr[i + 1], arr[high]);

    // Return the index of the pivot element
    return i + 1;
}

// Recursive function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays on both sides of the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void displayArray(int arr[], int size) {
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int MAX_SIZE = 6;
    int arr[MAX_SIZE] = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    displayArray(arr, MAX_SIZE);

    quickSort(arr, 0, MAX_SIZE - 1);

    displayArray(arr, MAX_SIZE);

    return 0;
}
