#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a = -1, b = -1;

        int expSum = 0, actualSum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];  // repeated
                }
                s.insert(grid[i][j]);
            }
        }

        expSum = (n * n) * (n * n + 1) / 2;

        b = expSum + a - actualSum; // missing

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }


int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

   
    vector<int> result = findMissingAndRepeatedValues(grid);

   
    cout << "Repeated: " << result[0] << endl;
    cout << "Missing: " << result[1] << endl;

    return 0;
}