// 第一反應: 往四個角落去延伸而不是上下左右
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  // TODO: memory 可以再降低, 因為不需要n*n步長
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int current_max_length = 0;
    vector<vector<int>> dp(m, vector(n, 0));
    // 先利用左右, 再利用角落
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // 跳過0 init corner-case
        if (i == 0 || j == 0 || matrix[i][j] == '0') {
          dp[i][j] = matrix[i][j] - '0';
        }
        else {
          int connected_check =min(dp[i-1][j], dp[i][j-1]);
          // 自己是1 把之前的總長度加上自己
          dp[i][j] = min(dp[i-1][j-1], connected_check) + 1;
        }
        current_max_length = max(current_max_length, dp[i][j] );
      }
    }
    cout<<current_max_length;
    return current_max_length * current_max_length;
  }
};