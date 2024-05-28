// 第一反應: 時間O(n*n/2) 每個都要找過, 然後找比目前元素大的, 用dp儲存出現個數
// 可以從第一次掃過的時候用目前收集到幾個元素以及目前的比他小的有幾個元素去做收斂
// 目標收斂到時間O(n log(n))
#include<bits/stdc++.h>
using namespace std;

// O((1+k)*k / 2), dp寫法
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> sub;
    // 一邊掃描一邊確認目前元素的個數
    for (int ele : nums) {
      if (sub.empty() || sub[sub.size() - 1] < ele) {
        sub.push_back(ele);
      }
      else {
        // 把最陣列中最靠近ele並且比ele大的換掉
        auto it = lower_bound(sub.begin(), sub.end(), ele);
        cout << *it << " " << ele << endl;
        *it = ele;
      }
    }
    for (auto ele : sub) {
      cout << ele << endl;
    }
    return sub.size();
  }
};