#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
  int x;
  cin >> x;
  return x;
}

void solve() {
  int n = nxt(), m = nxt(), d = nxt();
  int current = 1e9;
  int cnt = 0;
  vector<int> a(m);
  generate(all(a), nxt);
  a.insert(a.begin(), 1);
  a.push_back(n + 1);
  auto f = [&](int x) {
    return (x + d - 1) / d;
  };
  for (int i = 1; i <= m; ++i) {
    int x = f(a[i + 1] - a[i - 1]) - f(a[i] - a[i - 1]) - f(a[i + 1] - a[i]);
    if (x < current) {
      current = x;
      cnt = 0;
    }
    if (x == current) {
      cnt += 1;
    }
  }
  for (int i = 0; i <= m; ++i) {
    current += f(a[i + 1] - a[i]);
  }
  cout << current << " " << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = nxt();
  while (t--) {
    solve();
  }

  return 0;
}