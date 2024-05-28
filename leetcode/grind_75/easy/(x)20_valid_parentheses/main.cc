// https://leetcode.com/problems/valid-parentheses/description/
#include<vector>
#include <bits/stdc++.h>
#include<stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stack1;
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[') {
        stack1.push(c);
      }
      else {
        if (stack1.empty() ||
          (c == ')' && stack1.top() != '(') ||
          (c == '}' && stack1.top() != '{') ||
          (c == ']' && stack1.top() != '[')
          ) {
          return false;
        }
        stack1.pop();
      }
    }
    return stack1.empty();
  }
};