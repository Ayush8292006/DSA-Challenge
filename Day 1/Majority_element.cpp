#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Brute force
// int mazority(vector<int> &nums, int n){
//     for(int i=0;i<n;i++){
//         int count = 0;

//         for(int j=0;j<n;j++){
//             if(nums[i] == nums[j]){
//                 count++;
//             }
//             if(count > n/2){
//                 return nums[i];
//         }
//     }
// }
// }



// better approach
// int mazority(vector<int> &nums, int n){
//     unordered_map<int,int> mp;
//     for(int i=0;i<n;i++){
//         mp[nums[i]]++;
//     }
//     for(auto it: mp){
//         if(it.second > n/2){
//             return it.first;
//         }
//     }
//     return -1;
// }

// optimal approach

int mazority(vector<int> &nums, int n){
    int freq = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}



int main(){
    vector<int> nums = {3,2,3};
    int n = nums.size();

    int mazorityElement = mazority(nums, n);
    cout << "The majority element is: " << mazorityElement << endl;
}