#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
typedef long long ll;

using namespace std;


// file debug
// #include <fstream>
// std::ifstream read;
// ll f_cin() {

//   ll num;
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

void solve() {

  ll n, m;
  // n = f_cin();
  // m = f_cin();
  cin >> n >> m;
  vector<ll>vec(n);
  vector<ll>vec2(m);
  for (int i = 0; i < n; i++) {
    ll _;
    cin >> _;
    // _ = f_cin();
    vec[i] = _;
  }
  for (int i = 0; i < m; i++) {
    ll _;
    cin >> _;
    // _ = f_cin();
    vec2[i] = _;
  }

  //NOTE: 因為要看的是差額最小的 有可能中間的元素才是差額最小 e.g [1 10 18] [5 11 100]
  sort(vec.begin(), vec.end());
  sort(vec2.begin(), vec2.end());

  ll min_1 = 1e9;
  for (int i = 0; i < n; i++) {
    auto p = lower_bound(vec2.begin(), vec2.end(), vec[i]);
    ll d = abs((*p) - vec[i]);
    if (d < min_1) min_1 = d;
  }

  for (int i = 0; i < m; i++) {
    auto p = lower_bound(vec.begin(), vec.end(), vec2[i]);
    ll d = abs((*p) - vec2[i]);
    if (d < min_1) min_1 = d;
  }

  cout << min_1;




}
int main() {
  // debug
  // read.open("small_04.txt");
  // ======

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // int t = 0;
  // cin >> t;
  // while (t--) {
  solve();
  // }

  return 0;
}