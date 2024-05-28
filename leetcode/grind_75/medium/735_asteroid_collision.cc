// 第一反應: two-pointer 兩個stack 如果遇到不同號就pop並相撞, 如果遇到同類就push
// 左邊開始的遇到 -號 推, 右邊相反
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    // 減少成一個就可以了, 用一個bool 來判斷該stack是否該與目前的元素進行碰撞
    // 兩個pointer的話時間複雜理論上會減半, 但是空間增加. 看測資取捨
    stack<int> res;
    for (int a : asteroids) {
      bool destroyed = false;
      while (res.size() && res.top() > 0 && a < 0 && !destroyed) {
        // TODO: abs vs * -1?
        if (res.top() >= abs(a)) destroyed = true;
        if (res.top() <= abs(a)) {
          res.pop();
        }
      }

      if (!destroyed) res.push(a);
    }
    vector<int>ans(res.size());
    for (int i = ans.size() - 1; i >= 0; i--) {
      ans[i] = res.top();
      res.pop();
    }

    return ans;
  }
};