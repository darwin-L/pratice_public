// https://leetcode.com/problems/valid-palindrome/description/
// 將index設定由右到左以及由左到右掃描, 發現不一樣的就break, 如果長度為1直接true
// 回文的找法, 還算可以
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
      // else if 可以加速一半的case
      if (!isalnum(s[start])) {
        start++;
        continue;
      }
      else if
        (!isalnum(s[end])) {
        end--;
        continue;
      }

      if (tolower(s[start]) != tolower(s[end])) return false;
      start++;
      end--;
    }
    return true;
  }
};