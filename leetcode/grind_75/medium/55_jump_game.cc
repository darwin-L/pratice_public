// 第一反應: 一維的最短路徑, 2617_minumun_number_of_visited_cells_in_grid簡單版
// 不能用取目前局部最大, 因為有無解的路. e.g. [4,2,0,0,1,1,4,4,4,0,4,0] -> true
// 所以要用自身的變量與下一步做取捨
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums[0] == 0 && nums.size() > 1) return false;
    int m = nums.size() - 1;
    int max_idx = 0;
    for (int i = 0; i < m; i++) {
      // [1,0,1,0] -> out of max_idx
      if (i > max_idx) break;
      max_idx = max(nums[i] + i, max_idx);
    }
    cout << max_idx;
    return  max_idx >= m;
  }
};

// failed
class Solution {
public:
  bool canJump(vector<int>& nums) {
    int m = nums.size() - 1;
    if (nums[0] == 0 && nums.size() > 1) return false;
    int idx = 0;
    for (int i = 0; i < m; i++) {
      int current_max = 0;
      cout << current_max << " " << i << " " << nums[i] << " " << idx << endl;
      for (int j = i + 1; j <= i + nums[i]; j++) {
        if (j > m) break;
        if (nums[j] >= current_max) {
          current_max = max(current_max, nums[j]);
          idx = j;
        }


      }
      cout << current_max << " " << i << " " << nums[i] << " " << idx << endl;
      cout << endl;
      if (i + nums[i] >= m) return true;
      if (current_max == 0) {
        return false;
      }
      i = idx - 1;
    }
    return true;
  }
};