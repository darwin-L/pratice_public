// 第一反應: 直接用置換的寫法, 每次排的時候去比較與答案是否一致, 一致的話回傳下一個排序的元素
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<vector<int>> permutation;
  vector<int>ans;
  vector<int>target;
public:
  // Narayana Pandita algorithms
  void nextPermutation(vector<int>& nums) {
    cout << std::next_permutation(nums.begin(), nums.end());
    int n = nums.size();
    int k = 0, l = 0;
    for (k = n - 2; k >= 0; k--) {
      if (nums[k] < nums[k + 1]) break;
    }
    if (k < 0) {
      reverse(nums.begin(), nums.end());
    }
    else {
      for (l = n - 1; l > k; l--) {
        if (nums[l] > nums[k]) break;
      }
      swap(nums[l], nums[k]);
      reverse(nums.begin() + k + 1, nums.end());
    }

  }

};