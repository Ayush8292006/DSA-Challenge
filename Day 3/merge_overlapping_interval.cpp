#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() <= 1) 
        return intervals;

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        vector<int>& last = result.back();

        if(intervals[i][0] <= last[1]) {
            last[1] = max(last[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> ans = mergeIntervals(intervals);

    for(auto &v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}