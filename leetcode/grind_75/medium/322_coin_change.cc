// 第一反應: 無限背包, 找最小需要的步數, 先從最小價值的開始塞, 直到塞到最大, 但這樣複雜度O(n^2)
// 價值只會是正數, 所以不用考慮負數維度
#include<bits/stdc++.h>
using namespace std;
// failed, sort過後不能保證最小塞到最大一定有解
//  e.g. [186,419,83,408] 6249 -> expect: 20
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    int global_min_steps = INT_MAX;
    int target = amount;
    for (int i = 0; i < coins.size(); i++) {
      int current_min_steps = 0;
      int inner_idx = i;
      target = amount;

      while (target != 0)
      {
        if (target < 0 && inner_idx != 0) {
          target += coins[inner_idx];
          // current_min_steps--;

          inner_idx--;
          target -= coins[inner_idx];
        }
        else {
          cout << " " << target << " " << coins[i] << " " << i;
          target -= coins[inner_idx];
          current_min_steps++;
          if (inner_idx == 0 && target < -10000) {
            current_min_steps = INT_MAX;
            break;
          }
        }

      }
      global_min_steps = min(global_min_steps, current_min_steps);
    }
    if (global_min_steps == INT_MAX) return -1;
    return global_min_steps;
  }
};



class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    // 2d -> 1d  因為只需要取有可能的最小步數
    // dp[coins.size()][amount+1] -> dp[amount + 1]
    vector<int> tabu(amount + 1, INT_MAX - 1);
    tabu[0] = 0;
    for (int c : coins) {
      for (int coin_idx = c; coin_idx <= amount; coin_idx++) {
        // performance condition. skips the unsolvable cell, this condition can work because the value is not negative
        if (tabu[coin_idx - 1] != INT_MAX - 1) {
          tabu[coin_idx] = min(tabu[coin_idx], tabu[coin_idx - c] + 1);
        }
      }
    }
    for (auto ele : tabu) {
      cout << ele << endl;
    }
    if (tabu.back() >= INT_MAX - 1) {
      return -1;
    }
    else {
      return tabu.back();
    }
  }
};