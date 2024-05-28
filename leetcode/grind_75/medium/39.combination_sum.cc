// 第一反應:  簡化版無限背包問題(只有耐重), 同個可一直放, 先查出所有排列, 然後看能不能江某個元素拆成自己更小的元素
// 只需要根據目標取組合
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // 枚舉所有組合, 如果值不夠就自己把自己塞進去
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 如果comination那個method回傳值改成void 不用bool 判斷是否pop, 讓作業系統自己去展開function call的話, 可以不用這個sort
    // 但在目前的實做方式中, 沒有sort的話會少掉 往前面元素搜尋的路線
    // e.g. [4,2,8] target=8
    sort(candidates.begin(), candidates.end());
    vector<vector<int>>ans;
    vector<int> current_combination;
    bool _ = combination(candidates, target, current_combination, 0, 0, ans);
    return ans;
  }
  bool combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans) {
    if (currSum > target) return true; //找下一個候選物
    if (currSum == target) {
      ans.push_back(currComb);
      return false;
    }

    for (int i = currIndex; i < candidates.size(); i++) {
      currComb.push_back(candidates[i]); 
      currSum += candidates[i];
      // 這邊因為是無限背包所以要把這次的變數放進去 (i)
      bool need_pop_flag = combination(candidates, target, currComb, currSum, i, ans);
      if (need_pop_flag) {
        currComb.pop_back();
        currSum -= candidates[i];
      }
    }
    // 找過所有可能依然沒有需要的
    return true;
  }

};