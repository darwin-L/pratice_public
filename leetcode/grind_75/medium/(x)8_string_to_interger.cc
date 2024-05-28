// 第一反應: 讀到 " "跳過字元, 讀到 - 結果乘上 -1, 然後每一個進位/10 %10 
// "-+12" = 0 WTF?
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int myAtoi(string s) {
    int string_idx = 0;
    int sign_flag = 1;
    bool sign_flag2 = false;
    int base = 0;
    while (s[string_idx] == ' ')
    {
      string_idx++;
    }
    // 不能分開寫因為會交錯
    while(s[string_idx] == '-' || s[string_idx] == '+') {
      if(s[string_idx] == '-') sign_flag2 = !sign_flag2;
      string_idx++;
    }
    // if (s[string_idx] == '-' || s[string_idx] == '+') {
    //   sign_flag = 1 - 2 * (s[string_idx++] == '-');
    // }
    while (s[string_idx] >= '0' && s[string_idx] <= '9')
    {
      if (base > INT_MAX / 10) {
        if (sign_flag) {
          return INT_MIN;
        }
        else {
          return INT_MAX;
        }
      }
      base = 10 * base + (s[string_idx] - '0');
      cout << (s[string_idx] - '0') << endl;
      string_idx++;
    }
    if(sign_flag2) {
      return base * -1;
    } else {
      return base;
    }
    return base * sign_flag;
  }
};