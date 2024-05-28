// 第一反應: 轉成字串處理
// follow-up: 不轉成字串的話判斷位數然後用shift的方式
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    // corner-case 尾數為0, 該案例也不能透過後面的迴圈檢查出來
    if (x > 0 && x % 10 == 0) return false;
    int reversed = 0;
    // 直接從中間切開就不用判斷位數
    while (x > reversed) {
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }
    return (x == reversed) || (x == reversed / 10);
  }
};