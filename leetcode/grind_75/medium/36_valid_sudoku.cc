// 第一反應: 設定81(9*9)個set去做, 有find就false
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  //yep, 沒啥特別的
  bool isValidSudoku(vector<vector<char> >& board)
  {
    int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j)
        if (board[i][j] != '.')
        {
          int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
          if (used1[i][num] || used2[j][num] || used3[k][num])
            return false;
          used1[i][num] = used2[j][num] = used3[k][num] = 1;
        }

    return true;
  }
};