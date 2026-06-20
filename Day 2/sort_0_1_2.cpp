#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int noz = 0, noo = 0, notw = 0;

    // count 0s, 1s, 2s
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) noz++;
        else if (nums[i] == 1) noo++;
        else notw++;
    }

    // overwrite array
    for (int i = 0; i < n; i++) {
        if (i < noz) nums[i] = 0;
        else if (i < noz + noo) nums[i] = 1;
        else nums[i] = 2;
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    cout << "Sorted array: ";
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}