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

struct Fraction
{
  int p, q;
  int total_score;
  int full_score_count;
  int position_id;
  // bool operator < (const Student& b) const {
  //   return total_score > b.total_score || (total_score == b.total_score && full_score_count > b.full_score_count);
  // }

  // string compare(const Fraction& s1, const Fraction& s2) {
  //   // if()
  // }

  void add_score(const int input_score) {
    total_score += input_score;
    if (input_score == 100)full_score_count++;
  }
};



void solve() {

  int n, t;
  cin >> n >> t;
  vector<Fraction> vec(n);
  for (int i = 0; i < n; i++) {

    cin >> vec[i].p;
    cin >> vec[i].q;
  }

  unordered_map<int, int> OperationMap = {
    {2,4},
    {3,2},
    {1,3}
  };

  for (int i = 0; i < t; i++) {
    int op;
    cin >> op;
    int op_count = OperationMap[op];
    cout<<op_count;
    for (int j = 0; j < op_count; j++) {
      int _;
      cin >>_;
    }
  }

}
int main() {
  // debug
  // read.open("test.txt");
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