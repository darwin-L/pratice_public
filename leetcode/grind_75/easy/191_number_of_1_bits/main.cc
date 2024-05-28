// 第一反應: 迴圈(遞迴)直到數字小於1, 每次%2看有沒有1 然後/2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

  int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
      // 與%2等價
      if (n & 1 == 1) {
        count++;
      }
      cout << n << endl;
      // 與 /2 等價
      n >>= 1;
    }
    // 更簡潔的寫法, 讓減法去處理進位, 讓and把有意義的位元保留下來
    // while (n) {
    //   n &= (n - 1);
    //   count++;
    // }

    return count;
  }
};