// 第一反應: 如果left一開始就比input大, 從right開始找, right找到比自己小就停下來
// 這個在一些corner-case worst-case會比 binary-search還要差
// e.g. [10000,2,3,4,5,6,7,8,9,10 ... approach to 9998] taget = 1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      if (target == nums[i]) return i;
      if (target < nums[i]) break;

    }
    for (int i = nums.size() - 1; i >= 0; i--) {

      if (target == nums[i]) return i;
      // handle the corner condititon
      if (i > 0 && nums[i] < nums[i - 1]) break;
    }
    return -1;
  }
};

// TODO: binary-search 實做