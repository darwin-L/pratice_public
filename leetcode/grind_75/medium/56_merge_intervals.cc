// 第一反應: 題目其實條件沒有寫的很清楚
// 1. 區間內沒有排序過嗎(還真沒排序過)
// 儲存end, 當任一start 低於end就合併區間, 在有排序的前提下就一路找完即可

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& input) {
      if(input.size() == 0)    return {};
      vector<vector<int>> ans;
      sort(input.begin(), input.end(),[](const vector<int>a, const vector<int> b) { return a < b;});
      ans.push_back(input[0]);
      for(int i = 1; i < input.size(); i++) {
        if(ans.back()[1] < input[i][0]) {
          ans.push_back(input[i]);
        } else {
          ans.back()[1] = max(ans.back()[1],input[i][1]);
        }
      }
      return ans;
    }
};