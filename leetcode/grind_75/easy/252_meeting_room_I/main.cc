// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// Example 1:

// Input: 
// [[0,30],[5,10],[15,20]]

// Output: false

// Example 2:

// Input: [[7,10],[2,4]]
// Output: true


#include <bits/stdc++.h>
using namespace std;

// 看到區間overlap, 先排序start(ASC), 如果往後的end小於前一個, 則有交集

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // a[0] < b[0] 為false 就不換
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};