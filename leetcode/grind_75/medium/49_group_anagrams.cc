// 第一反應: 每一個單字給一個字母unordered_map(因為字母出現次數不只一次), 如果一樣放入同類型vector
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> string_map;
    // 直接用string當key, 不用每個字元去檢查
    for(string s: strs) {
      string _ = s;
      sort(_.begin(), _.end());
      string_map[_].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto ele: string_map) {
      ans.push_back(ele.second);
    }
    return ans;
  }
};