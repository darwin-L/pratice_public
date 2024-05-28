// 第一反應: 一路掃到陣列尾端, 再設定一個unordered_map如果當下元素大於下一個元素就放入, 然後每次往下map裡面所有元素都要+1
// 用upper_bound 或 lower_bound去做map的掃描
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<int> window;
    for (int i = 0; i < temperatures.size(); i++) {
      int currTemperature = temperatures[i];
      //這邊的實做用stack, 抓最新進入的那一個,因為他是最小的
      while (!window.empty() && currTemperature > temperatures[window.top()]) {
        int j = window.top();
        window.pop();
        cout<<i<<" "<<j<<endl;
        ans[j] = i - j;
      }

      window.push(i);
    }
    return ans;
  }
};