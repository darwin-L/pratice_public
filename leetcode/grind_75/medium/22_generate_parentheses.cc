// 第一反應: 用一般的置換算法, 每一次要推入ans時檢查是否有未閉合的括號 '(' = 1, ')' = -1
#include<bits/stdc++.h>
using namespace std;
// 照第一反應會TLE
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    set<string> ans;
    string input = "";
    while (n--)
    {
      input += "()";
    }


    recursive(ans, input, 0);
    vector<string> output;
    for (auto ele : ans) {
      cout << ele << endl;
      output.push_back(ele);
    }
    return output;

  }
  void recursive(set<string>& ans, string input, int left) {
    if (left > input.length() - 1) {
      int pushable = 0;
      for (char c : input) {
        if (c == '(') pushable++;
        if (c == ')') pushable--;
        if (pushable < 0) return;
      }
      if (pushable == 0) ans.insert(input);
      return;
    }
    for (int right = left; right < input.length(); right++) {
      if (left != right) {
        swap(input[left], input[right]);
      }
      recursive(ans, input, left + 1);
      swap(input[left], input[right]);
    }
  }
};

// 卡塔蘭數 Cn = C (2n, n) / (n+1) = (2n)! / (n! * (n+1)!)
// 可以驗算遞迴出來的結果
// 一個左邊括號一定會對應一個右邊括號, 所以以左邊括號為0去開始迭代. 因為一定要把n跑完, 所以當兩邊為0的時候再輸出

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    addingpar(ans, "", 0, n);
    return ans;
  }
  void addingpar(vector<string>& v, string str, int left, int right) {
    // 如果需要列出所有可能, 這個條件會改變
    // TODO: 可以試一下
    if (left == 0 && right == 0) {
      v.push_back(str);
      return;
    }
    if (left > 0) { addingpar(v, str + ")", left - 1, right); }
    if (right > 0) { addingpar(v, str + "(", left + 1, right - 1); }
  }
};