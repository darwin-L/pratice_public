// 第一反應: 用unordered_map, 
// 但因為題目有特殊限制: 大於一半數量的元素就為主要元素, 並且該元素一定存在
// 所以果要在O(1) space的話, 能用boyer-moore majority vote algorithm
// 但如果該case沒有眾數抑或著沒有邊界, 此演算法無效
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    for (int current_num : nums) {
      if (count == 0) candidate = current_num;

      if (current_num == candidate) {
        count++;
      }
      else {
        count--;
      }
    }
    return candidate;
  }
};