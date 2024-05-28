 
#include <bits/stdc++.h>
using namespace std;

inline int nxt() {
  int x;
  cin >> x;
  return x;
}
void solve() {
	int left, right;
  left = nxt();
  right = nxt();
  // 右邊能用整除用2整除用2 或是中間寬度大於4 
	if ((right % 2 == 0 && right > 2) || (right - left > 0 && right >= 4)) {
		int x = right;
		if (x % 2 != 0) x--;
		cout << 2 << ' ' << (x - 2) << '\n';
		return;
	}
	for (int x = left; x <= right; x++) {
		for (int i = 2; i * i <= left; i++) {
			if (left % i == 0) {
				cout << i << ' ' << (left - i) << '\n';
				return;
			}
		}
	}
	cout << "-1\n";
}
 
int main() {
	std::cin.tie(NULL); std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
}