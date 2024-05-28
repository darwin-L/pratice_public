// 第一反應: two subset -> 所以陣列總和一定要為雙數, 目標定為 該數除以2
//  sort陣列之後 找出排列之後加總, 
// 從大的開始, two-pointer也無法
// 要用dp e.g.  [3,3,3,4,5]. [2,2,1,1], [14,9,8,4,3,2]
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
      total += nums[i];
    }
    if ((total & 1) == 1) {
      return false;
    }

    total /= 2;
    if (total == 1) return true;

    // 製表dp, 也可不用const int 直接塞變數進去
    const int TABLE_SIZE = total + 1;
    bool dp[TABLE_SIZE];
    // equal as dp[TABLE_SIZE] = {false}, but which is illegal due to init check
    memset(dp,false,TABLE_SIZE);
    

    // 這是一個整數規劃子問題: 在一數列中枚舉裡面所有元素有沒有能夠剛好等於目標值的
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = total; j >= nums[i]; j--) {
        if (dp[j - nums[i]]) dp[j] = true;
      }

    }
    return dp[total];
  }
};
//TODO: 寫出其他解法, 看sublime3