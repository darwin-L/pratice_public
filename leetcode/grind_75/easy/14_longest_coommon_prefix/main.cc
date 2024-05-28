// 第一反應: 先找第一次遍歷, 因為是前輟而不是夾在中間的字串
// 將找到的字元跟具有找到的目標逐漸收斂字串比對

// 共同字串只要有一個不符合就等於沒有, 不用全部符合, 所以照字串長度排序之後, 比對最小的即可
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string longestCommonPrefix(vector<string>& v) {
    string ans = "";
    sort(v.begin(), v.end());
    int n = v.size();
    string first = v[0], last = v[n - 1];
    for (int i = 0;i < first.size();i++) {
      if (first[i] != last[i]) {
        return ans;
      }
      ans += first[i];
    }
    return ans;
  }
};