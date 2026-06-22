#include <bits/stdc++.h>
using namespace std;

/// brute force


// int lengthOfLongestSubstring(string s) {
//    int n = s.size();
   
//    int maxLen = 0;
//    for(int i=0;i<n;i++){
//         int hash[256] = {0};
//         for(int j=i;j<n;j++){
//             if(hash[s[j]]==1){
//                 break;
//             }
//             else{
//                 hash[s[j]] = 1;
//                 int len = j-i+1;
//                 maxLen = max(maxLen,len);
//             }
//         }

//    }
//    return maxLen;
// }

int lengthOfLongestSubstring(string s){
    int n = s.size();

    int hash[256];
    for(int i = 0; i < 256; i++) hash[i] = -1;

    int l = 0, r = 0, maxLen = 0;

    while(r < n){
        if(hash[s[r]] != -1 && hash[s[r]] >= l){
            l = hash[s[r]] + 1;
        }

        hash[s[r]] = r;

        int len = r - l + 1;   
        maxLen = max(maxLen, len);

        r++;
    }

    return maxLen;
}



int main() {
    string s = "abcabcbb";

    int ans = lengthOfLongestSubstring(s);
    cout << ans;

    return 0;
}