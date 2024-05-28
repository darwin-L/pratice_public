// 第一反應:  三個迴圈, 2d陣列+長度控制, 子問題是一個數列取n個有幾種取法, 在這個情境中n是變數了
// [3,2,4,1]
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;

    ans.push_back({});
    for (int i = 0; i < nums.size(); i++) {
      vector<int> temp;
      for (int j = i; j < nums.size(); j++) {
        temp.push_back(nums[j]);
      }
      divide_and_con(nums, temp.size(), ans);
    }
    for (auto ele : ans) {
      for (auto ele2 : ele) cout << ele2;
      cout << endl;
    }
    ans.push_back(nums);
    return ans;
  }

  void divide_and_con(vector<int>& input, int lenght, vector<vector<int>>& ans) {
    for (int i = 0; i < input.size(); i++) {
      vector<int> temp;
      for (int j = i; j < i + (lenght - 1); j++) {
        temp.push_back(input[j % input.size()]);
      }
      sort(temp.begin(), temp.end());
      if (!temp.empty()) ans.push_back(temp);
    }
  }
};