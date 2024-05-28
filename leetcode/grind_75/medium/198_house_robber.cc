// 第一反應: 變形背包問題. init問題是這題的難點, 因為是"隔一間以上"且沒有限制取的總量所以拿兩個變數互相max
// 注意[2,1,1,2], [2,100,100,1]的情況
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int rob(vector<int>& nums) {
    // 製表的變形, a-> memo[0] = 0, b-> memo[1] = nums[0]
    int a = 0;
    int b = 0;
    for (int i = 0; i < nums.size(); i++) {
      if ((i & 1) == 0) {
        a = max(b, a + nums[i]);
      }
      else {
        b = max(a, b + nums[i]);
      }
    }
    return max(a, b);
  }
};