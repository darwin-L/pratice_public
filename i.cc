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

void solve() {
  int n;
  n = nxt();

  int m[101][101];

  int i = 0;
  while (i<n)
  {
    int j = 0;
    while (j<n)
    {
      m[i][j] = nxt();
      j++;
    }
    
    i++;
  }

  for(auto ele: m) {
    for(auto ele2: ele.being()) {
      cout<<ele;
    }
    cout<<"\n";
  }
  

  // int len = matrix.length;
  // for (int layer = 0; layer < len / 2; layer++) {
  //   int firstPos = layer;
  //   int lastPos = (len - 1) - layer;
  //   for (int i = firstPos; i < lastPos; i++) {
  //     int offset = i - firstPos;
  //     int topLeft = matrix[firstPos][i];
  //     // 暫存
  //     matrix[firstPos][i] = matrix[lastPos - offset][firstPos];
  //     matrix[lastPos - offset][firstPos] = matrix[lastPos][lastPos - offset];
  //     matrix[lastPos][lastPos - offset] = matrix[i][lastPos];
  //     matrix[i][lastPos] = topLeft;
  //   }
  // }
  return;

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