#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1;i<n;i++){
        bool swapped = false;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) 
            break;
    }
}
