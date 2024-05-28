// 第一反應: 找雙數的, 如果有一個字母的只能+1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    int odds = 0;
    for (char c = 'A'; c <= 'z'; c++) {
      // (& 1) 操作相等於(% 2), 但更快
      odds += count(s.begin(), s.end(), c) & 1;
    }

    return s.size() - odds + (odds > 0);
  }
};
