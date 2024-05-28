// https://cses.fi/problemset/task/1630/

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

  int n;
  cin >> n;
  vector<pair<int, int>>p_vec;

  for (int i = 0; i < n; i++) {
    int _, _2;
    cin >> _ >> _2;
    p_vec.push_back({ _,_2 });
  }
  sort(p_vec.begin(), p_vec.end(), std::less<pair<int, int>>());

  ll t = 0;
  ll value = 0;
  for (int i = 0; i < p_vec.size();i++) {
    t += p_vec[i].first;
    value += p_vec[i].second - t;
  }
  cout << value;



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