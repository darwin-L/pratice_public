#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)

using namespace std;

inline int nxt() {
  int x;
  cin >> x;
  return x;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = nxt();
  int m = nxt();
  vector<vector<int>> p(n, vector<int>(m, 0));
  int i = 0;
  while (n--)
  {
    int m2 = m;
    int j = 0;
    while (m2--)
    {
      p[i][j] = nxt();
      j++;
    }
    i++;

  }

  int min = 99999999;
  vector<int>ans;
  for (int idx2 = 0; idx2 < p[0].size(); idx2++) {
    int t = 0;
    for (int idx = 0; idx < p.size(); idx++) {
      if (p[idx][idx2] < min) {
        min = p[idx][idx2];
        t = idx;
      }
    }
    ans.push_back(t);
  }
  for(auto ele: ans){
    cout<<ele;
  }

  // for (auto ele : p) {
  //   for (auto ele2 : ele) {
  //     cout << ele2;
  //   }
  //   cout << "\n";
  // }


  return 0;
}