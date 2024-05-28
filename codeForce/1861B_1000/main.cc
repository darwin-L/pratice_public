#include <bits/stdc++.h>

#define endl '\n'

#define all(v) v.begin(), v.end()
#define pb push_back
#define rep(i, a, n) for (int i = (a); i < (n); ++i)


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void solve() {
  string a, b;
  cin >> a >> b;

  rep(i, 0, (int)a.size() - 1) {
    if (a[i] == '0' && b[i] == '0') {
      if (a[i + 1] == '1' && b[i + 1] == '1') {
        cout << "YES" << endl;
        return;
      }
    }

  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}