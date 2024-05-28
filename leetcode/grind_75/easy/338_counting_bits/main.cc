#include <bits/stdc++.h>
using namespace std;
// 看過才知道 -> 從第一個值開始, 每一個值往前取 and 運算之後剛好可以看出進位的情況
// 但因為那個值沒有被轉成二進位, 所以拿之前的結果來用
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int>ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int offset = (i & (i - 1));

      ans[i] = ans[offset] + 1;
    }
    return ans;
  }
};