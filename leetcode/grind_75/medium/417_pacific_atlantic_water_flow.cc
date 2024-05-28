// 第一反應: 交界處(heights[0][n],heights[m][0])為init點, 當陣列裡面有元素小於他就是答案
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int m = 0, n = 0;
  vector<vector<int>> ans;
  vector<vector<bool>>atlantic, pacific;
  queue<pair<int, int>>q;

  // DFS
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (!size(heights)) return ans;
    m = size(heights), n = size(heights[0]);
    atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
    
    // 要取交匯處所以不能只從init點開始, 而是得從邊掃描過去並且掃描兩次確認有重合
    for (int i = 0; i < m; i++) {
      dfs(heights, pacific, i, 0);
      dfs(heights, atlantic, i, n - 1);
    }
    for (int i = 0; i < n; i++) {
      dfs(heights, pacific, 0, i);
      dfs(heights, atlantic, m - 1, i);
    }
    return ans;
  }
  void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j) {

    if (visited[i][j]) return;
    visited[i][j] = true;

    if (atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});

    if (i + 1 < m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j);
    if (i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
    if (j + 1 < n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1);
    if (j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);

  }
};