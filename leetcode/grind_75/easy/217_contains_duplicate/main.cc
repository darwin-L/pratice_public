// 第一反應: unordered_map, 找到底
// 用unordered_set的長度可以判斷是否有重複字元, 但不知道是哪一個, 精準符合題意
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
  }
};