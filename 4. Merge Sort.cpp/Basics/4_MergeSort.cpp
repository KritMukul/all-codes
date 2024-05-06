#include<bits/stdc++.h>
using namespace std;

vector<int> merg(vector<int> &arr, int low, int mid, int high){
    int left = low, right = mid + 1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    } 
    return temp;
}

vector<int> mergeSort(vector<int> & arr, int low, int high){
    if(low >= high){
        return {};
    }
    int mid = (low + high) /2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    vector<int> ans = merg(arr, low, mid, high);
}

int main(){
    vector<int> arr = {4, 5, 3, 8, 1, 0};
    vector<int> ans = mergeSort(arr, 0, arr.size() - 1);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout<< ans[i] << " ";
    }
    
    return 0;
}