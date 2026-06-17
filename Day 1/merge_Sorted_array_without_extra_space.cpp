#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int i = m - 1;          // last valid element in nums1
    int j = n - 1;          // last element in nums2
    int k = m + n - 1;      // last index of nums1
    
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    // Agar nums2 ke elements bach gaye ho
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for(int x : nums1) {
        cout << x << " ";
    }

    return 0;
}