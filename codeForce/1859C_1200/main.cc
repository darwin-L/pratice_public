/*
 * @Author:darwin.lang
 * @Date:2023-09-05 21:39:11
 * @LastEditors:darwin.lang
 * @LastEditTime:2023-09-05 22:25:25
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr double EPS = 1e-8;
const double PI = acos(-1.0);

constexpr int N = 510;

int T, n, a[N];


inline int nxt() {
  int x;
  cin >> x;
  return x;
}

void solve()
{

  cin >> n;
  int ans = 0;
  // 避免從0開始因為有乘法元素
  rep(i, 0, n + 1)
  {
    // front to end
    rep(j, 1, i + 1) {

      a[j] = j;
    }

    // end to front
    int m = n;
    rep(j, i + 1, n + 1) {
      a[j] = m;
      m -= 1;
    }


    int cur = 0, mx = 0;
    rep(j, 1, n + 1)
    {
      int v = j * a[j];
      cur += v;
      mx = max(mx, v);
    }
    ans = max(ans, cur - mx);
  }
  cout << ans << '\n';

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = nxt();
  while (t--) {
    solve();
  }
  // solve();
  return 0;
}