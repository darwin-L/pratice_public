#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
typedef long long ll;

using namespace std;


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

  vector<int> v;

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    v.push_back(int(s[i]) - 96);
  }

  vector<int> idx_v;
  idx_v.push_back(0);
  bool check[2 * int(1e5) + 1] = { false };

  // if (current_cost >= limit_of_vector) break;
  //  if (v[j] > v[i]) continue;
  // uncommon these two lines will fit some test case. but not all.
  // need to find the logic error
  
  // limit_of_vector  assume  first ele to last ele is the boundery of the loop
  // v[j] > v[i] is aim for choose the lower cost than higher cost because the vector direction

  int limit_of_vector = abs(v[0] - v[v.size()]);
  int current_cost = 0;
  for (int i = 0; i < v.size(); i++) {
    int min = 1e5;
    int temp_idx = -1;
    check[0] = true;
    // if (current_cost >= limit_of_vector) break;
    for (int j = 0; j < v.size(); j++) {
      if (i == j) continue;
      // if (v[j] > v[i]) continue;
      if (check[j]) continue;

      int current = abs(v[i] - v[j]);
      if (min > current) {
        min = current;
        temp_idx = j;
      }
    }

    if (temp_idx >= 0) {
      check[temp_idx] = true;
      i = temp_idx - 1;
      current_cost += min;
      idx_v.push_back(temp_idx);
    }

  }
  cout << current_cost << " " << idx_v.size() << '\n';
  for (auto ele : idx_v) {
    cout << ele + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}