#include <bits/stdc++.h>
#include <string_view>
#include <algorithm>
#include <ranges>
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

struct Fraction
{
  ll p, q;
  Fraction(int _p, int _q): p(_p), q(_q) {

    //分母為負把負號轉移到分子
    if (q < 0) {
      q = -q;
      p = -p;
    }
    int g = gcd(p,q);
    q /= g;
    p /= g;
  }

  bool operator<(const Fraction& f) const {
    return p * f.q < q* f.p;
  }
};



void solve() {
  // https://codeforces.com/gym/457183/problem/J 不想寫
  int n, t;
  cin >> n >> t;
  int arr[10] = {};

  for (int i = 0; i < n; i++) {
    arr[i] =
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