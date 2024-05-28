// 第一反應: 因為一定是兩個兩個一組, 所以看input_interval的左右個別適合放在哪個元素當中
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // 因為input_interval只有一組, 直接在交集在左右哪邊就可以了
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    int i = 0;
    vector<vector<int>> ans;

    // 在原始intervals之前沒有交集, 
    while (i < n && intervals[i][1] < newInterval[0])
    {
      ans.push_back(intervals[i]);
      i++;
    }

    // 將交集的區間直接拿netInterval去做更新, 然後推入結果中
    while (i < n && newInterval[1] >= intervals[i][0]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    ans.push_back(newInterval);

    // 將剩餘的區間補完
    while (i < n) {
      ans.push_back(intervals[i]);
      i++;
    }
    return ans;
  }
};