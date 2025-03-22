#include<bits/stdc++.h>
using namespace std;

int min_changes(vector<vector<int>> v, int n, int m) {
    
}

int main(){
    int t; cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        int i = 0, j = 0;
        vector<vector<int>> mat(n, vector<int> (m));
        while (i < n)
        {
            while (j < m)
            {
                cin>>mat[i][j];
                j++;
            }
            i++;
        }
        cout<<min_changes(mat, n, m)<<endl;    
    }
    
    return 0;
}