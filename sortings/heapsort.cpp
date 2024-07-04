#include <iostream>
using namespace std;

void heapify(int arr[], int n, int idx){
    int largest = idx;
    int left=idx*2+1;
    int right=idx*2 + 2;

    if(largest<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(largest<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=idx){
        swap(arr[largest],arr[idx]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[], int n, int i){
    for(int i=n/2-1;i>=0;--i){
        heapify(arr,n,i);
    }
    for(int i=n-1; i>0; --i){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[size];

    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr, size);

    // Perform Heap Sort
    heapSort(arr, size);

    cout << "Sorted array: ";
    display(arr, size);

    return 0;
}