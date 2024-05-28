#include <bits/stdc++.h>
#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
typedef long long ll;

using namespace std;


// file debug
// #include <fstream>
// std::ifstream read;
// int f_cin() {

//   int num;
//   if (read.is_open()) {
//     read >> num;
//   }
//   else {
//     std::cin >> num;
//   }

//   return num;
// };
// =====================================


// only work for interger
ll b_sqrt(ll x) {
  ll res = 0;
  for (ll k = 1ll << 30; k != 0; k /= 2) {
    if ((res + k) * (res + k) <= x) {
      res += k;
    }
  }
  return res;
}
ll fpow(ll i, int j) {
  ll res = 1, tmp = i;
  // tmp = tmp * tmp;
  while (j > 0) {
    if (j & 1) res = res * i;
    i = i * i;
    j >>= 1;
  }
  return res;
}

// 自訂比較時, 若兩個參數的值一樣, 要回傳false(不交換) e.g. all elements are the same
// 所以要交換的條件盡量寫非相等的
bool compare(const int x, const int y) {
  if ((x & 1) != (y & 1)) {
    if ((x & 1) == 0) return true;
    return false;
  }
  if ((x & 1) == 0) {
    if (x < y) return true;
    return false;
  }
  else {
    if (x > y) return true;
    return false;
  }
}

void solve() {
  int n;
  cin >> n;
  const int constrin_max_num = 2e5;
  int num[constrin_max_num] = {};
  for (int i = 0; i < n; i++) {
    int _;
    cin >> _;
    num[i] = _;
  }
  sort(num, num + n, compare);
  for (int i = 0; i < n; i++) {
    cout << num[i] << " ";
  }

}
int main() {
  // debug
  // read.open("test.txt");
  // ======

  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  // int t = 0;
  // cin >> t;
  // while (t--) {
  solve();
  // }

  return 0;
}