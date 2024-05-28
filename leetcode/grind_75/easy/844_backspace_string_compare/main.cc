// 第一反應: stack包char, 遇到#就pop, 最後比較
// 直接取backspace後的字串即可, 但注意corner-case中先有backspace的話不能小於0
// 不能使用 __builtin_popcount
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string build(string s) {
    int c = 0;
    for (int i = 0;i < s.size();i++) {
      if (s[i] == '#') {
        c--;
        c = max(0, c);

      }
      else {
        // 把原本#的字元取代掉
        s[c] = s[i];
        c++;
      }

    }
    return s.substr(0, c);
  }
  bool backspaceCompare(string s, string t) {
    return build(s) == build(t);
  }
};