// 第一反應: 先sort nums[i].end > nums[i].start 就移除
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        if (intervals.size() == 0)
            return 0;
        
        // 排序第二個元素, 因為第二個元素一定大於第一個元素  
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        vector<int> prev = intervals[0];

        int ans = 0;
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (prev[1] > intervals[i][0])
            {
                ans++;
            }
            else
            {
                prev = intervals[i];
            }
        }
        return ans;
    }
};