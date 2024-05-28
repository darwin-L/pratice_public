// 第一反應: 對於有限定取n個數的, 先固定某一變量之後 其他的用逼近的方式逼近它
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int target = -nums[i];
      
      int left_idx = i + 1;
      int right_idx = nums.size() - 1;
      while (left_idx < right_idx)
      {
        int sum =  nums[left_idx] + nums[right_idx];
        if (sum == target) {
          ans.insert({ nums[i], nums[left_idx], nums[right_idx] });
          left_idx++;
          right_idx--;
          continue;
        }

        if (sum < target) {
          left_idx++;
          continue;
        }
        if (sum > target) {
          right_idx--;
          continue;
        }
      }
    }

    vector<vector<int>> final_ans;
    for (auto ele : ans) {
      final_ans.push_back(ele);
    }
    return final_ans;
  }
};

