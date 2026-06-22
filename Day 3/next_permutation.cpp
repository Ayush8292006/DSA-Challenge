#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int piv = -1;
    for(int i = n-2; i>=0;i--){
        if(nums[i]<nums[i+1]){
            piv = i;
            break;
        }
    }

    if(piv==-1){
        reverse(nums.begin(),nums.end());
    }
    else{
        for(int i = n-1;i>piv;i--){
            if(nums[i]>nums[piv]){
                swap(nums[i],nums[piv]);
                break;
            }
        }
    }

    reverse(nums.begin()+piv+1,nums.end());


}

int main() {
    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    for(int x : nums) {
        cout << x << " ";
    }

    return 0;
}