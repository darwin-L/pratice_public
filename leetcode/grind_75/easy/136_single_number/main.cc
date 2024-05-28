#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  // xor的特性-> 1. 可以交換彼此 2. 頻率為2時會為0, 並且可以容納其他數字, 但溢位問題要特別注意
  // 題目特性: 
  // 1. Each element in the array appears twice except for one element which appears only once.
  // 2. -3 * 104 <= nums[i] <= 3 * 104
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (auto x : nums)
      ans ^= x;
    return ans;
  }
};