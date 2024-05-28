// https://codeforces.com/contest/1557/problem/B
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

  int n, k;
  cin >> n >> k;



  // if the value are not distinct, this solver will invalid

  // vector<pair<int, int>> vec(n);
  // for (int i = 0; i < n; i++) {
  //   int _;
  //   cin >> _;
  //   // location and value is the key
  //   vec[i].first = _;
  //   vec[i].second = i;
  // }

  // sort(vec.begin(), vec.end());
  // int ans = 1;
  // for (int i = 0; i < n - 1; i++) {
  //   if (vec[i].second != vec[i + 1].second - 1) ans++;
  // }

  // if (ans > k) {
  //   cout << "NO" << '\n';
  // }
  // else {
  //   cout << "YES" << '\n';
  // }



  // when first element is smaller then second element push it into vector
  // it can be done reverse
  // FIXME: WA on test3
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    int _;
    cin >> _;
    // location and value is the key
    vec[i] = _;
  }
  vector<vector<int>> ans_vec;
  for (int i = 0; i < n - 1; i++) {
    vector<int> temp_vec;
    for (int j = i; j < n - 1; j++) {
      if (vec[j] == vec[j + 1] - 1) {
        cout<<j<<'\n';
        temp_vec.push_back(vec[j]);
        temp_vec.push_back(vec[j + 1]);
        cout<<temp_vec.size()<<'\n';
        j++;
      }
      else {
        if(temp_vec.size()>0) {
          cout<<j<<'\n';
          ans_vec.push_back({1});
        }
        ans_vec.push_back({ 1 });
        i = j;
      }
    }

  }
  cout<<ans_vec.size()<<'\n';
  if (ans_vec.size() < k) {
    cout << "YES" << '\n';
  }
  else {
    cout << "NO" << '\n';
  }


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