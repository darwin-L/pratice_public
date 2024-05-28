// https://codeforces.com/contest/1839/problem/B
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

void solve() {

  int n;
  cin >> n;

  vector<pair<int, int>> p_vec(n);

  int index_of_last_lamp = 0;
  for (int i = 0; i < n; i++) {
    int constranct_value, reward;
    cin >> constranct_value >> reward;
    p_vec[i].second = reward;
    p_vec[i].first = constranct_value;

    if (index_of_last_lamp < constranct_value)  index_of_last_lamp = constranct_value;
  }

  // sort(p_vec.begin(), p_vec.end(), sortbyCond);
  sort(p_vec.begin(), p_vec.end(), greater<pair<int, int>>());

  int count_constracnct = 0;
  ll total = 0;
  // 每個lamp的constranct - 1 就是該constranct下所有可以被拿來使用的
  // FIXME: 思考一下這題的constra
  for (int i = 0; i < p_vec.size();) {

    int count_boundary = p_vec[i].first;
    for (int j = 0; i < n; j++) {
      if (p_vec[i].first != count_boundary) {
        break;
      }
      // cout << p_vec[i].first << " " << p_vec[i].second << '\n';
      if (j < count_boundary) {
        total += p_vec[i].second;
      }
      i++;

    }
  }
  cout << total << '\n';

}
int main() {
  // debug
  // read.open("test.txt");
  // ======

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}