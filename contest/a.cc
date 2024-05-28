#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
typedef long long ll;

using namespace std;


// only work for interger
inline ll b_sqrt(ll x) {
  ll res = 0;
  for (ll k = 1ll << 30; k != 0; k /= 2) {
    if ((res + k) * (res + k) <= x) {
      res += k;
    }
  }
  return res;
}
inline ll fpow(ll i, int j) {
  ll res = 1, tmp = i;
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
  string s;
  cin>>s;

  int count_a = 0;
  int count_b = 0;
  bool ans = false;
  int x = 1;
  int y = max(count(s.begin(), s.end(),'A'),count(s.begin(), s.end(),'B'));
  for(int i = 0; i < s.size(); i ++) {
    if(s[i] == 'A')  count_a++;
    if(s[i] == 'B')  count_b++;

    if(count_a == y || count_b == y) {
      if(i != s.size() - 1) {
        y++;
      } else {
        ans = true;
        break;
      }
    }
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
