#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int i = 0, j = 0;
    while(i< a.size() && j < b.size()) {
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6}, b = {2, 3, 3, 5, 6, 6, 7};
    vector<int> intersectionArr = intersection(a, b);

    for(int i = 0; i < intersectionArr.size(); i++) {
        cout<<intersectionArr[i]<<" ";
    }
    return 0;
}