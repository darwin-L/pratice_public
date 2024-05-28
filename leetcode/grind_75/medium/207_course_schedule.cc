// 第一反應: 檢查有沒有鎻的cycle, 用stack要是回到自己就紀錄長度. 
// 如果可以要完成的課堂數減去鎖的數量有剩餘, 還是可以返回成功
#include<bits/stdc++.h>
using namespace std;
// 整體陣列不大 2000 * 5000, 所以可以每一個元素弄成一個vector互相鎖定
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> courses_matrix(numCourses, vector<int>());
    vector<int> locked(numCourses, 0);
    for (auto& ele : prerequisites) {
      courses_matrix[ele[1]].push_back(ele[0]);
      locked[ele[0]]++;
    }
    // 把沒有檔修的課程先排進去處理, 就不用sort了, 因為能被解開的會直接進queue
    queue<int>q;
    for (int i = 0; i < numCourses; i++) {
      if (locked[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      numCourses--;
      // 如果有無法解開的課程, 就不會進到queue裡面
      for (auto next : courses_matrix[curr]) {
        // 注意要儲存變數, 原本題目的測資不夠完整
        // 這個動作保證了每一個課堂在不同課堂的連鎖下也能被推入
        // e.g. n= 4, [[1,0],[2,0],[3,1],[3,2]]
        locked[next]--;
        int _ = locked[next];
        if (_ == 0) q.push(next);
      }
    }
    return numCourses == 0;
  }
};