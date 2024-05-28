// 第一反應: 遇到0就count, 最後加到另一個vector的尾端
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int offset = 0;
    for (int i = 0;i < nums.size();i++) {
      if (nums[i] == 0) {
        offset++;
      }
      // else-if 避免 該element為0和offset > 0同時觸發溢位
      else if (offset > 0) {
        int t = nums[i];
        nums[i] = 0;
        nums[i - offset] = t;
      }
    }
  }
};