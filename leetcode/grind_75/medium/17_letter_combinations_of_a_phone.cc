// 第一反應: [abc, def] 各取一個共有幾種取法, 重複不算, 不取不算
// n*n*n ... ->看每一個數字鍵裡面有幾個英文字母
// 因為有m個n 用遞迴寫會比較直覺 
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  vector<string> pad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
  vector<string> output;

  void recursive(string digtis, vector<string>& output, string& temp, int pad_index) {
    if (pad_index == digtis.size()) {
      output.push_back(temp);
      return;
    }
    string val = this->pad[digtis[pad_index] - '0'];
    for (int i = 0; i < val.size(); i++) {
      temp.push_back(val[i]);
      recursive(digtis, output, temp, pad_index + 1);
      temp.pop_back();
    }
  }
public:
  vector<string> letterCombinations(string digits) {
    // vector<string> pad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    if (digits.empty()) {
      return {};
    }
    string temp;
    recursive(digits, output, temp, 0);
    return output;
  }
};