/*
 * @Author:darwin.lang
 * @Date:2022-05-16 22:46:02
 * @LastEditors:darwin.lang
 * @LastEditTime:2022-05-23 22:01:45
 * @Description:
 */
// problem url: http://codeforces.com/problemset/problem/1139/C
// reference url: https://codeforces.com/problemset/problem/1139/C
// reference url2 (better look, but can improve) :  https://github.com/darwin-L/CodeForces/blob/master/1139C-EdgyTrees.cpp

#include <bits/stdc++.h>

using namespace std;

const int boundary = 1e5 + 1000;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, k;
ll finished_array[boundary], mapping_array[boundary];
ll binary_pow(ll a, ll b)
{
  ll res = 1;
  a = a % mod;
  while (b)
  {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res % mod;
}

void init()
{
  for (ll i = 1; i <= boundary; i++)
  {
    finished_array[i] = i;
    mapping_array[i] = 1;
  }
}

ll find_direction(ll x)
{
  if (x != finished_array[x])
  {
    return finished_array[x] = find_direction(finished_array[x]);
  }
  return finished_array[x];
}

int main(void)
{
  init();
  scanf("%lld%lld", &n, &k);
  for (ll i = 1; i <= n - 1; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c == 0)
    {
      ll x = find_direction(a);
      ll y = find_direction(b);
      finished_array[x] = y;
      mapping_array[y] = mapping_array[y] + mapping_array[x];
    }
  }
  ll ans1 = binary_pow(n, k);
  ll ans = 0;
  for (ll i = 1; i <= n; i++)
  {
    if (find_direction(i) == i)
    {
      ans = (ans % mod + binary_pow(mapping_array[i], k)) % mod;
    }
  }
  cout << (ans1 - ans + mod) % mod << endl;
}
