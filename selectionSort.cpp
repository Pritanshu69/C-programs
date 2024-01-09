#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int midIndex = i;

//REVIEW - finding the minimum element

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[midIndex]){
                midIndex = j;
            }
        }
        //NOTE - swap the minimum found element with the first elemenet
        swap(arr[i], arr[midIndex]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n;

    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n]; //REVIEW - Ignore this error
        cout<<"Enter the elements of the array: ";
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<"Original array: ";
        printArray(arr,n);
        
        selectionSort(arr, n);

        cout<<"Sorted array: ";
        printArray(arr,n);

        return 0;

}