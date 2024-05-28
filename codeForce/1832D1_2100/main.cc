//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;
 
//#define int long long
typedef long long ll;
 
typedef unsigned long long ul;
typedef unsigned int ui;
//ll mod = 1;
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
const int mod17 = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
 
using ld = long double;
typedef pair<ld, ld> LDP;
const ld eps = 1e-10;
const ld pi = acosl(-1.0);
 
template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
vector<T> vmerge(vector<T>& a, vector<T>& b) {
	vector<T> res;
	int ida = 0, idb = 0;
	while (ida < a.size() || idb < b.size()) {
		if (idb == b.size()) {
			res.push_back(a[ida]); ida++;
		}
		else if (ida == a.size()) {
			res.push_back(b[idb]); idb++;
		}
		else {
			if (a[ida] < b[idb]) {
				res.push_back(a[ida]); ida++;
			}
			else {
				res.push_back(b[idb]); idb++;
			}
		}
	}
	return res;
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	//if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
//mod should be <2^31
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= (int)mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += (int)mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}
 
ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
 
ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 2000005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/
 
//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}
 
//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}
LP operator+(LP a, LP b) {
	return { a.first + b.first,a.second + b.second };
}
LP operator+=(LP& a, LP b) {
	a = a + b; return a;
}
LP operator-(LP a, LP b) {
	return { a.first - b.first,a.second - b.second };
}
LP operator-=(LP& a, LP b) {
	a = a - b; return a;
}
 
mt19937 mt(time(0));
 
const string drul = "DRUL";
string senw = "SENW";
//DRUL,or SENW
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
 
//-----------------------------------------

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
  // 排序進入的操作大小, 並依題目減去1, 後面的right, left vector 加上1做shift
	sort(all(a));
	vector<int> b(n);
	rep(i, n)b[i] = a[i] - i;
	vector<ll> rb(n + 1);
	rep(i, n)rb[i + 1] = rb[i] + b[i];
	vector<int> lb(n + 1);
	lb[0] = mod17;
	rep(i, n) {
		lb[i + 1] = lb[i];
		chmin(lb[i + 1], b[i]);
	}
  auto query = [&](int k) {
    if (k < n) {
      ll res = min(lb[k] + k, a[k]);
      return res;
    }
		// 如果是操作是偶數的話
    if ((k - n) % 2) {
      int num = (k - (n - 1)) / 2;
      auto isok = [&](ll x) {
        if (a.back() < x) return false;
        if (lb[n - 1] + k < x) return false;
        // 貪心目前最大的操作, 與目前最大的元素 與 最大操作次數 乘上操作-1次(不能變色) 之和
        ll s = rb[n - 1] + (ll)k * (n-1) + a[n-1];
        // 如果該值大於可以操作的
				s -= x * n;
				// cout<<"? "<< x<< " "<< s <<"\n";
				return s >= num;
      };
      // left_ele, right_index
			ll le = -mod17, ri = 2 * mod17;
			// 貪心算法
			while (ri - le > 1) {
				ll mid = (le + ri) /2;
				if (isok(mid)) le = mid;
				else ri = mid;
			}
			return le;
    } else {
			int num = (k-n) /2;
			auto isok = [&](ll x) {
				if (lb[n] + k < x) return false;
				ll s = rb[n] + (ll)k * n + a[n];
				s -= x * n;
				// cout<<"? "<< x<< " "<< s <<"\n";
				return s >= num;
      };
			ll le = -mod17, ri = 2 * mod17;
			// 貪心算法
			while (ri - le > 1) {
				ll mid = (le + ri) /2;
				if (isok(mid)) le = mid;
				else ri = mid;
			}
      return le;
		}
    assert(false);
    return (ll) - 1;
  };
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}