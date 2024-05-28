#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
typedef long long ll;

using namespace std;

inline int nxt() {
  int x;
  cin >> x;
  return x;
}

void solve() {
  int n;
  cin >> n;


  // NOTE: this question can be solved by using double for
  // but time-complexity is O(n^2)



  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(n);
  for (int i = 0;i < n;++i) {
    int ai; cin >> ai;
    a[i] = make_pair(ai, i);
    int bi; cin >> bi;
    b[i] = make_pair(bi, i);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a[0].second != b[0].second) {
    cout << max(a[0].first, b[0].first);
  }
  else {
    // after sorted, get the first or second element
    cout << min(a[0].first + b[0].first, min(max(a[0].first, b[1].first), max(a[1].first, b[0].first)));
  }


  // below is failed code


  // int job_a, job_b;
  // job_a = int(1e5) + 1;
  // job_b = int(1e5) + 1;
  // int flag = int(1e5) + 1;

  // int a[int(1e5) + 1] = { 0 };
  // int b[int(1e5) + 1] = { 0 };


  // // no needed
  //   int min_first_round = int(1e9);
  //   rep(i, 0, n) {
  //     int t1, t2;
  //     cin >> t1 >> t2;
  //     a[i] = t1;
  //     b[i] = t2;
  //     if (t1 + t2 < min_first_round) {
  //       min_first_round = t1 + t2;
  //     }
  //   }

    // pair<int, int> xa,xb;
    // xa = {int(1e9), int(1e9)};
    // xb = {int(1e9), int(1e9)};
    // int min_a, min_b;
    // min_a = int(1e9);
    // min_b = int(1e9);
    // rep(i, 0, n) {
    //   if (a[i] < xa.first) {
    //     xa.first = a[i];
    //   }
    //   if (b[i] < xb.first) {
    //     xb.first = b[i];
    //   }

    //   if (xa.first < xa.second) {
    //     // cout<<xa.first<<":"<<xa.second;
    //     swap(xa.first,xa.second);
    //     // cout<<xa.first<<":"<<xa.second;
    //     // return;
    //   }

    //   if (xb.first < xb.second) {
    //     swap(xb.first,xb.second);
    //   }
    // }
    // cout<<xa.first << " " << xb.first << '\n';
    // cout<<xa.second << " " << xb.second << '\n';
    // // TODO: this condition is quite bad
    // if (xa.second + xb.second != min_first_round) {
    //   int ans = min(xa.first, xb.first);
    //   cout << ans;
    // }
    // else {
    //   int compare_1 = max(xa.first, xa.second);
    //   int compare_2 = max(xb.second, xb.first);
    //   int ans = max(compare_2,compare_1);
    //   cout << min(ans,min_first_round);
    // }



}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // int t = nxt();
  // while (t--) {
  solve();
  // }

  return 0;
}

