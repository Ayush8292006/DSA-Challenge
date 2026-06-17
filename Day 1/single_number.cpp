#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;

    // Count frequency
    for(int num : nums) {
        mp[num]++;
    }

    // Find element with frequency 1
    for(auto it : mp) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = singleNumber(nums);

    cout << "Single number is: " << result << endl;

    return 0;
}