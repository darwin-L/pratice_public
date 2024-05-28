// https://codeforces.com/contest/1830/problem/C
#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int fac[1000005], invfac[1000005], inv[1000005];
int C(int x, int y)
{
  return fac[x] * invfac[y] % mod * invfac[x - y] % mod;
}
int f(int n)
{
  if (n & 1) return 0;
  n /= 2;
  return C(n + n, n) * inv[n + 1] % mod;
}
int a[300005];
mt19937_64 rnd(22637261);
map<int, int> mp;
void solve()
{
  int n, k;
  cin >> n >> k;
  for (int i = 0;i <= n;i++) a[i] = 0;
  for (int i = 1;i <= k;i++)
  {
    int l, r;
    cin >> l >> r;
    int X = rnd();
    a[l] ^= X, a[r + 1] ^= X;
  }
  for (int i = 1;i <= n;i++) a[i] ^= a[i - 1];
  mp.clear();
  for (int i = 1;i <= n;i++) mp[a[i]]++;
  int ans = 1;
  for (auto x : mp) ans = (ans * f(x.second)) % mod;
  cout << ans << "\n";
}
signed main()
{
  inv[1] = fac[0] = fac[1] = invfac[0] = invfac[1] = 1;
  for (int i = 2;i <= 1000000;i++)
  {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
    fac[i] = fac[i - 1] * i % mod;
  }
  for(int i: inv) {
   cout << i << "\n";
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}