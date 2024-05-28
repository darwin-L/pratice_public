// 第一反應: 用一個stack去處理未完成的運算元
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    std::stack<int> stack;
    // 可以加個檢查map裡面有沒有剩餘的運算元或是數字(最後會剩一個答案)
    for (string& s : tokens) {
      if (!operation_map.count(s)) {
        stack.push(stoi(s));
      }
      else {
        int op1 = stack.top();
        stack.pop();
        int op2 = stack.top();
        stack.pop();
        // 記得是先後面的元素再前面的元素
        stack.push(operation_map[s](op2, op1));
      }
    }
    return stack.top();
  }
private:
  unordered_map<string, function<int(int, int) > > operation_map = {
          { "+" , [](int a, int b) { return a + b; } },
          { "-" , [](int a, int b) { return a - b; } },
          { "*" , [](int a, int b) { return a * b; } },
          { "/" , [](int a, int b) { return a / b; } }
  };
};