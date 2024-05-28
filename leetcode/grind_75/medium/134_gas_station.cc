// 第一反應: 因為他是單向的vector,而且必須返回原點. 所以直接抓最小cost的那個開始
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int target = INT_MAX;
    int current_sum = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      current_sum += gas[i] - cost[i];
      if (current_sum <= target) {
        target = current_sum;
        idx = i+1;
      }
    }
    if(current_sum < 0) {
      return  -1;
    } else {
      // 0開始的陣列, idx要取餘從0開始
      return idx % n;
    }
  }
};