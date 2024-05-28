// 第一反應: 因為只有一個間斷, 且每個元素不重複, 皆為正數, 直接用梯形公式抓面積(避開0), 算差額就可
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int total = (1 + nums.size()) * nums.size() / 2;
    for (int i = 0; i < nums.size(); i++) {
      total -= nums[i];
    }
    return total;
  }
  //xor
  int missingNumber_xor(vector<int>& nums) { 
    // 用長度做init
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      res ^= i;
      res ^= nums[i];
    }
    return res;
  }
};

