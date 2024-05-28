// 第一反應: 三個迴圈, 2個迴圈給地圖, 1個迴圈給方位
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1, bottom = n - 1, top = 0;
    int direction = 1;

    // 地圖的兩個迴圈可以用變數合併成一個while
    while (left <= right && top <= bottom)
    {
      if (direction == 1) {
        for (int i = left; i <= right; i++)  ans.push_back(matrix[top][i]);
        direction = 2;
        top++;
      }
      if (direction == 2) {
        for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
        direction = 3;
        right--;
      }
      if (direction == 3) {
        for (int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
        direction = 4;
        bottom--;
      }
      if (direction == 4) {
        for (int i = bottom; i >= top; i--)  ans.push_back(matrix[i][left]);
        direction = 1;
        left++;
      }
    }
    // prevent redundancy element, when not using if-else-if statement
    while (ans.size() > m * n)
    {
      ans.pop_back();
    }

    return ans;

  }
};