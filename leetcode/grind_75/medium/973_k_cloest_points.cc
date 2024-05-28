// 第一反應: 算出每個人的距離和他的編號做成pair, 接著nth_element來用
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    nth_element(points.begin(), points.begin() + K - 1, points.end(),
      [](vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
      });
    return vector<vector<int>>(points.begin(), points.begin() + K);
  }
};