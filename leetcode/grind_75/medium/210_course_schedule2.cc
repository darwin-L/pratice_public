// 第一反應: 跟207相同, 最後empty queue的時候改成陣列
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> courses_matrix(numCourses, vector<int>());
    vector<int> locked(numCourses, 0);
    for (auto& ele : prerequisites) {
      courses_matrix[ele[1]].push_back(ele[0]);
      locked[ele[0]]++;
    }
    queue<int>q;
    for (int i = 0; i < numCourses; i++) {
      if (locked[i] == 0) {
        q.push(i);
      }
    }

    vector<int>ans;
    while (!q.empty())
    {
      int curr = q.front();
      ans.push_back(curr);
      q.pop();

      numCourses--;
      for (auto next : courses_matrix[curr]) {
        locked[next]--;
        int _ = locked[next];
        if (_ == 0) q.push(next);
      }
    }

    if ( numCourses> 0) {
      // return ans;
      return vector<int>();
    }
    else {
      return ans;
    }

  }
};