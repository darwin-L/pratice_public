// 第一反應: 轉型再相加, 但c++中二進位字串轉型有點困難, 也沒有現成lib使用
// 就從字串最後一位開始加, 記得進位即可
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int idx_a = a.size() - 1;
    int idx_b = b.size() - 1;
    while (idx_a >= 0 || idx_b >= 0 || carry)
    {

      // 該條件避免idx 到負數overflow, 因為有兩個idx可能一正一負
      if (idx_a >= 0) {
        carry += a[idx_a] - '0';
        idx_a--;
      }
      if (idx_b >= 0) {
        carry += b[idx_b] - '0';
        idx_b--;
      }
      ans += (carry & 1) + '0';
      carry /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;

  }
};