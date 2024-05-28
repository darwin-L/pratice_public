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
  int x, y;
  int p, q;
  void set(int _x, int _y) {
    x = _x;
    y = _y;

    p = x;
    q = y;

    //分母為負把負號轉移到分子
    if (q < 0) {
      q = -q;
      p = -p;
    }
  }

  bool operator<(const Fraction& f) const {
    return p * f.q < q* f.p;
  }
};



void solve() {

  int op;
  cin >> op;
  cin.get();
  string _;
  getline(cin, _);


  char determinzer;
  if (op == 1) {
    determinzer = ' ';
  }
  else {
    determinzer = ',';
  }

  auto split = _
    | std::ranges::views::split(determinzer)
    | std::ranges::views::transform([](auto&& str) { return std::string_view(&*str.begin(), std::ranges::distance(str)); });


  vector<Fraction>vec;
  for (auto ele : split)
  {
    Fraction f;
    int cut = ele.rfind('/');
    string s = string(ele);

    f.set(stoi(s.substr(0, cut)), stoi(s.substr(cut + 1)));
    vec.push_back(f);

  }



  stable_sort(vec.begin(), vec.end());
  for (auto &ele : vec) {
    if (&ele == &vec.back()) {
      cout << ele.x << "/" << ele.y;
    }
    else {
      cout << ele.x << "/" << ele.y << determinzer;
    }

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