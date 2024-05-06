#include<bits/stdc++.h>
using namespace std;


int f(vector<int> &arr, int low, int high){
    int i = low, j = high, pivot = arr[low];
    while (arr[i] < pivot && i <= high)
    {
        i++;
    }

    while (arr[j] > pivot)
    {
        j--;
    }
    if(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
}

void quickSort(vector<int> &arr, int low, int high){
    int i = low, j = high;
    if(low < high){    
        int pIndex = f(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}
int main(){
    vector<int> arr = {4, 5, 7, 1, 3, 2, 6, 9};

    quickSort(arr, 0, arr.size() - 1);
    return 0;
}