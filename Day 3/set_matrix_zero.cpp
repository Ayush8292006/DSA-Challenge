#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // mark rows & cols
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // set zeroes
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] || col[j]){
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 1, 0},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(arr);

    for(auto &row : arr){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}