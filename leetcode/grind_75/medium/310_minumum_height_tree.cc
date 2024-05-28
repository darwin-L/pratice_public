// 第一反應: 與最多條邊相連的任一點, 只要他還有子樹, 都可以當頂點
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> ans;
    if (n == 1)    return vector<int>{0};

    // 注意這裡用set
    unordered_map<int, unordered_set<int>> matrix;
    for (auto ele : edges) {
      matrix[ele[0]].insert(ele[1]);
      matrix[ele[1]].insert(ele[0]);
    }
    vector<int>leaves;
    for (auto ele : matrix) {
      if (matrix[ele.first].size() == 1) leaves.push_back(ele.first);
    }

    // 這邊的作法與我的想法相反, n減去所有邊長為1的點, 及為剩下大於1的點(與最多邊相連的所有子樹)
    // 接著每次把自己剩餘相鄰的點互相移掉, 直到size為1
    cout<<leaves.size()<<endl;
    // n > 2 是要避免自己連接自己的corner
    while (n > 2)
    {
      n -= leaves.size();
      vector<int> posible_leavse;
      for(int i = 0; i < leaves.size(); i++) {
        int next_node = *(matrix[leaves[i]]).begin();
        // 移除自己的子樹也移除對方跟自己的連結
        matrix[leaves[i]].erase(next_node);
        matrix[next_node].erase(leaves[i]);
        cout<<next_node<<endl;
        if(matrix[next_node].size() == 1) posible_leavse.push_back(next_node);
      }
      // 更新剩餘子樹 避免與條件相呼應以避免 [0,1][1,0]這種東西
      leaves = posible_leavse;
      cout<<n;
    }
    return leaves;

  }
};