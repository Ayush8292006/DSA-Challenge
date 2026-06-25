#include <iostream>
#include <vector>
using namespace std;


    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        if(matrix.empty() || matrix[0].empty())
            return ans;

        int m = matrix.size();
        int n = matrix[0].size();
        int total_elements = m * n;

        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startCol = 0;

        int count = 0;

        while(count < total_elements){

            for(int i = startCol; i <= endingCol && count < total_elements; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            for(int i = startingRow; i <= endingRow && count < total_elements; i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            for(int i = endingCol; i >= startCol && count < total_elements; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            for(int i = endingRow; i >= startingRow && count < total_elements; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }


int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans = spiralOrder(matrix);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}