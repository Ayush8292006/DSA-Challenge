#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0, j = n - 1;
    int maxWater = 0;

    while (i < j) {
        int h = min(height[i], height[j]);
        int w = j - i;
        int area = h * w;

        maxWater = max(maxWater, area);

        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum Water: " << maxArea(height);

    return 0;
}