#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Sorting
int findDuplicate_sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) return nums[i];
    }
    return -1;
}

// 2. Negative Marking
int findDuplicate_marking(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
        int index = abs(nums[i]);
        if (nums[index] < 0) return index;
        nums[index] *= -1;
    }
    return -1;
}

// 3. Cyclic Sort
int findDuplicate_cyclic(vector<int>& nums) {
    while (nums[0] != nums[nums[0]]) {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}

// 4. Floyd’s Cycle Detection
int findDuplicate_floyd(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    vector<int> a = nums, b = nums, c = nums, d = nums;

    cout << "Sort: " << findDuplicate_sort(a) << endl;
    cout << "Marking: " << findDuplicate_marking(b) << endl;
    cout << "Cyclic: " << findDuplicate_cyclic(c) << endl;
    cout << "Floyd: " << findDuplicate_floyd(d) << endl;

    return 0;
}