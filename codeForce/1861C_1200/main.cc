#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)

inline int nxt() {
  int x;
  cin >> x;
  return x;
}

void solve() {
  string S;
  cin >> S;

  bool ok = 1;
  stack<int> s;
  int N = S.size();
  int bad = 0, nice = -1;
  vector<int> p(N);
  rep(i, 0, N) {
    if (S[i] == '+') {
      s.push(i);
    }
    if (S[i] == '-') {
      int a = s.top();
      s.pop();
      if (p[a]) bad = 0;
    }
    if (S[i] == '1') {
      nice = i;
      if (bad) ok = 0;
    }
    if (S[i] == '0') {
      if ((int)s.size() < 2) ok = 0;
      else if (bad == 0) {
        int a = s.top();
        if (a < nice) ok = 0;
        bad = 1;
        p[a] = 1;
      }
    }
  }
  cout << (ok ? "YES\n" : "NO\n");
}




int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = nxt();
  rep(i, 0, t) solve();
}