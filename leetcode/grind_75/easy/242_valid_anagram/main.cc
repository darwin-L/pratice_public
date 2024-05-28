// 1. 用unorder_map去檢查每個字元的出現字數最後結算,
// 2. 可以用兩個字串數量直接判斷,但應該很少case是這樣的

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> char_count;

    for (auto x : s) {
      char_count[x]++;
    }
    for (auto x : t) {
      char_count[x]--;
    }

    for (auto x : char_count) {
      if (x.second != 0) return false;
    }
    return true;
  }
};