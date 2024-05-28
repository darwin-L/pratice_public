// 第一反應: 遇到每個1就找上下左右直到找到, 所有方位都要找過因為要找最小值
// 所有方位都找的話比較屬於第二個解法
// 這種搜尋算法架構分為 1. visited 2.找路線的判斷(上下左右) 3.權重判斷(最短邊的查表)

#include<bits/stdc++.h>
using namespace std;

// dijkstra
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    // ans可以捨棄掉直接替換成輸入的mat, 不助於理解就另外創造變數
    
    // 方向往右下, 但是檢查路線是上跟左
    vector<vector<int>> ans = mat;
    const int BOUNDARY = m + n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) continue;
        // BOUNDARY得先設置因為這個迴圈內只有檢查兩個方向
        int top = BOUNDARY, left = BOUNDARY;
        if (i - 1 >= 0) top = ans[i - 1][j];
        if (j - 1 >= 0) left = ans[i][j - 1];
        ans[i][j] = min(top, left) + 1;
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (mat[i][j] == 0) continue;
        int bottom = BOUNDARY, right = BOUNDARY;
        if (i + 1 < m) bottom = ans[i + 1][j];
        if (j + 1 < n) right = ans[i][j + 1];
        ans[i][j] = min(ans[i][j], min(bottom, right) + 1);
      }
    }
    return ans;
  }
};


// BFS
class Solution_BFS {
public:


  bool isvalid(int i, int j, int m, int n)
  {
    if (i == m || j == n || j < 0 || i < 0)
      return false;
    return true;
  }

  vector<vector<int>> dir = { {1,0},{0,1},{0,-1},{-1,0} };
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
  {
    queue<pair<int, int>> q;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, INT_MIN));
    for (int i = 0;i < m;i++) {
      for (int j = 0;j < n;j++)
      {
        if (matrix[i][j] == 0)
        {
          q.push({ i,j });
          ans[i][j] = 0;
        }
      }
    }
    while (!q.empty())
    {
      pair<int, int> curr = q.front();
      q.pop();
      for (auto& x : dir)
      {
        int i = curr.first + x[0];
        int j = curr.second + x[1];
        if (isvalid(i, j, m, n) && ans[i][j] < 0)
        {
          q.push({ i,j });
          ans[i][j] = ans[curr.first][curr.second] + 1;
        }
      }
    }
    return ans;
  }
};