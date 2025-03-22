#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    int n1 = A.size(), m1 = A[0].size();
    int n2 = B.size(), m2 = B[0].size();
    vector<vector<int>> ans(n1, vector<int>(m2, 0));
    if(m1 != n2) {
        cout<<"Matrices cannot be multiplied!";
        return ans;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            for (int x = 0; x < m1; x++) {
                ans[i][j] += A[i][x] * B[x][j];
            }
        }
    }
    return ans;
}

int main(){
    // Matrix A (2x3)
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Matrix B (3x2)
    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    // Matrix C (2x4)
    vector<vector<int>> C = {
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    vector<vector<int>> D;

    D = multiply(A, B);

    vector<vector<int>> ans;

    ans = multiply(D, C);

    for(auto it : ans) {
        for(auto it2 : it) {
            cout << it2 << " ";
        }
        cout<<endl;
    }
    return 0;
}