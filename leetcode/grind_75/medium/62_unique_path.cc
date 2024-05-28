// 經典dp題, 下一動的總數可以由上面一動推算出來
// TODO: 有一些省記憶體的方式可以改進一下, e.g. 不用儲存所有結果所以dp一維就好
// https://leetcode.com/problems/unique-paths/solutions/22954/c-dp/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
          dp[i][j] = dp[i - 1][j] + dp[i][j-1];
      }
    }
    return dp[m-1][n-1];
  }
};