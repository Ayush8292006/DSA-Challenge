#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0, col = n - 1;

        while (row < m && col >= 0) {
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int target = 5;

    if (Solution::searchMatrix(matrix, target))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}