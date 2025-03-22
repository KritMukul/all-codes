#include<bits/stdc++.h>
using namespace std;

static bool cust_sort(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int findPlatform(vector<int>& arr, vector<int>& dep) {
    vector<pair<int, int>> v;
    
    for(int i = 0; i < arr.size(); i++) {
        v.push_back({arr[i], dep[i]});
    }
    
    sort(v.begin(), v.end(), cust_sort);
    
    int i = 0, j = 0;
    int cnt = 0, maxi = 1;
    while(i < v.size() && j < v.size()) {
        if(v[i].first <= v[j].second) {
            cnt++;
            maxi = max(maxi, cnt);
            i++;
        }
        else {
            cnt--;
            j++;
        }
        
    }
    return maxi;
}


int main() {
    vector<int> a = {1404, 1255, 2006, 155, 923, 1022, 2327, 1931, 2022, 745, 2328, 656, 2300, 1332, 1225, 1608, 2001}, b = {2338, 1804, 2144, 1834, 1138, 2211, 2336, 2047, 2206, 1213, 2339, 1614, 2329, 2304, 1909, 1712, 2250};
    cout<< findPlatform(a, b);
}