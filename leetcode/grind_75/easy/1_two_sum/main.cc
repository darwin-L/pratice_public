// https://leetcode.com/problems/two-sum/
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// test case: -1, 0, 7, 10 target: 6

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
      // 這個改善的寫法有個條件很重要: Only one valid answer exists.
      // 不然得回到使用O(n^2)的寫法 -> 可能可以用區分正負數的方式, 不用到O(n^2)
      int target2 = target - nums[i];
      if (umap.count(target2)) {
        return { umap[target2], i };
      }
      umap[nums[i]] = i;
    }
    return {};
  }
};