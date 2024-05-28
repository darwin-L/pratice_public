// 第一反應: 旋轉矩陣
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    // reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i + 1; j < matrix[i].size(); ++j) {
        cout << j << endl;
        swap(matrix[i][j], matrix[j][i]);
      }

    }
  }

};