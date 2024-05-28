    #include <bits/stdc++.h>
    //#define fastcall __attribute__((optimize("-O3")))
    //#pragma GCC optimize(1)
    //#pragma GCC optimize(2)
    //#pragma GCC optimize(3)
    //#pragma GCC optimize("Ofast")
    //#pragma GCC optimize("inline")
    //#pragma GCC optimize("-fgcse")
    //#pragma GCC optimize("-fgcse-lm")
    //#pragma GCC optimize("-fipa-sra")
    //#pragma GCC optimize("-ftree-pre")
    //#pragma GCC optimize("-ftree-vrp")
    //#pragma GCC optimize("-fpeephole2")
    //#pragma GCC optimize("-ffast-math")
    //#pragma GCC optimize("-fsched-spec")
    //#pragma GCC optimize("unroll-loops")
    //#pragma GCC optimize("-falign-jumps")
    //#pragma GCC optimize("-falign-loops")
    //#pragma GCC optimize("-falign-labels")
    //#pragma GCC optimize("-fdevirtualize")
    //#pragma GCC optimize("-fcaller-saves")
    //#pragma GCC optimize("-fcrossjumping")
    //#pragma GCC optimize("-fthread-jumps")
    //#pragma GCC optimize("-funroll-loops")
    //#pragma GCC optimize("-fwhole-program")
    //#pragma GCC optimize("-freorder-blocks")
    //#pragma GCC optimize("-fschedule-insns")
    //#pragma GCC optimize("inline-functions")
    //#pragma GCC optimize("-ftree-tail-merge")
    //#pragma GCC optimize("-fschedule-insns2")
    //#pragma GCC optimize("-fstrict-aliasing")
    //#pragma GCC optimize("-fstrict-overflow")
    //#pragma GCC optimize("-falign-functions")
    //#pragma GCC optimize("-fcse-skip-blocks")
    //#pragma GCC optimize("-fcse-follow-jumps")
    //#pragma GCC optimize("-fsched-interblock")
    //#pragma GCC optimize("-fpartial-inlining")
    //#pragma GCC optimize("no-stack-protector")
    //#pragma GCC optimize("-freorder-functions")
    //#pragma GCC optimize("-findirect-inlining")
    //#pragma GCC optimize("-fhoist-adjacent-loads")
    //#pragma GCC optimize("-frerun-cse-after-loop")
    //#pragma GCC optimize("inline-small-functions")
    //#pragma GCC optimize("-finline-small-functions")
    //#pragma GCC optimize("-ftree-switch-conversion")
    //#pragma GCC optimize("-foptimize-sibling-calls")
    //#pragma GCC optimize("-fexpensive-optimizations")
    //#pragma GCC optimize("-funsafe-loop-optimizations")
    //#pragma GCC optimize("inline-functions-called-once")
    //#pragma GCC optimize("-fdelete-null-pointer-checks")
    //#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
    #define il inline
    #define re register
    #define ll long long
    #define ull unsigned ll
    #define db double
    #define ldb long db
    #define fi first
    #define se second
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define MP(x, y) make_pair(x, y)
    #define eb emplace_back
    #define i128 __int128
    using namespace std;
    namespace FastIO {
      const int iL = 1 << 20;
    //  #define GC() getchar()
      char ibuf[iL], *iS = ibuf + iL, *iT = ibuf + iL;
      #define GC() (iS == iT) ? \
      (iT = (iS = ibuf) + fread(ibuf, 1, iL, stdin), (iS == iT) ? EOF : *iS++) : *iS++
      template <class T>il void read(T &x) {
        x = 0;
        char c = GC(); bool flg = false;
        while(!isdigit(c)) {flg |= c == '-'; c = GC();}
        while(isdigit(c)) {x = (x << 1) + (x << 3) + (c & 15); c = GC();}
        if(flg) x = -x;
      }
      template <class T>il void gread(T &x) {
        x = 0;
        char c = getchar(); bool flg = false;
        while(!isdigit(c)) {flg |= c == '-'; c = getchar();}
        while(isdigit(c)) {x = (x << 1) + (x << 3) + (c & 15); c = getchar();}
        if(flg) x = -x;
      }
      il int read() {
        int x = 0;
        char c = GC(); bool flg = false;
        while(!isdigit(c)) {flg |= c == '-'; c = GC();}
        while(isdigit(c)) {x = (x << 1) + (x << 3) + (c & 15); c = GC();}
        return flg ? -x : x;
      }
      char Out[iL], *iter = Out;
      #define Flush() fwrite(Out, 1, iter - Out, stdout); iter = Out
      template <class T>il void write(T x, char LastChar = '\n') {
        int c[35], len = 0;
        if(x < 0) {*iter++ = '-'; x = -x;}
        do {c[++len] = x % 10; x /= 10;} while(x);
        while(len) *iter++ = c[len--] + '0';
        *iter++ = LastChar; Flush();
      }
    }
    using namespace FastIO;
    mt19937_64 rnd(time(0));
    #define N 50005
    #define M 15
    #define LOG 20
    #define inv2 499122177
    //#define inv2 500000004
    #define MOD 998244353
    //#define MOD 1000000007
    #define MOD1 1000000007
    #define MOD2 1000000009
    //int MOD;
    il int QP(int p, int n/*, int MOD*/) {
      int ans = 1;
      while(n) {
        if(n & 1) ans = 1ll * ans * p % MOD;
        p = 1ll * p * p % MOD; n >>= 1;
      }
      return ans;
    }
    int fac[N], ifac[N];
    il int C(int n, int m) {
      return n < 0 || m < 0 || n < m ? 0 : 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
    }
    //int pri[N], cnt, minp[N]; bool vis[N];
    il void INIT() {
    //  for(re int i = 2; i < N; ++i) {
    //    if(!vis[i]) pri[++cnt] = minp[i] = i;
    //    for(re int j = 1; j <= cnt && i * pri[j] < N; ++j) {
    //      vis[i * pri[j]] = 1, minp[i * pri[j]] = pri[j];
    //      if(!(i % pri[j])) break;
    //    }
    //  }
      fac[0] = 1; for(re int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
      ifac[N - 1] = QP(fac[N - 1], MOD - 2); for(re int i = N - 2; ~i; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
    }
    il string tostr(int x) {
      string s = "";
      do s += x % 10 + '0', x /= 10; while(x);
      reverse(s.begin(), s.end()); return s;
    }
    il bool notp(int x) {
      for(re int i = 2; i * i <= x; ++i)
        if(x % i == 0) return 1; return 0;
    }
    int n, m;
    int a[N][M], b[M];
    int to[N * M][M], cnt;
    il void WORK() {
      read(n), read(m);
      for(re int i = 0; i <= cnt; ++i)
        memset(to[i], 0, sizeof(to[i]));
      cnt = 0;
      for(re int i = 1; i <= n; ++i) {
        int x = 0;
        for(re int j = 1; j <= m; ++j) read(a[i][j]);
        for(re int j = 1; j <= m; ++j) b[a[i][j]] = j;
        for(re int j = 1; j <= m; ++j) {
          if(!to[x][b[j]])
            to[x][b[j]] = ++cnt;
          x = to[x][b[j]];
        }
      }
      for(re int i = 1; i <= n; ++i) {
        int ans = 0, x = 0;
        for(re int j = 1; j <= m; ++j) {
          if(!to[x][a[i][j]]) break; ans = j, x = to[x][a[i][j]];
        }
        write(ans, " \n"[i == n]);
      }
    }
    main() {
    //  int stacksize = 512 << 20;
    //  __asm__("movq %0, %%rsp\n"::"r"((char*)malloc(stacksize) + stacksize));
      int testid = 0, TCASE = 1; INIT();
    //  read(testid);
      read(TCASE);
    //  scanf("%d\n", &TCASE);
    //  cin >> TCASE;
      for(re int i = 0; i < TCASE; ++i) WORK();
      exit(0); return 0;
    }