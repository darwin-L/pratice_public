// 第一反應: 用交換的, 但這樣時間複雜度 depent by k 最差O((1+k)*k / 2)
// do it in-place with O(1) extra space -> 修改原本的陣列
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // well, 有印象就好.時間複雜度O(2n), 切一半之後左右整個reverse
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};