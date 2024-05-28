// 第一反應: 用兩個stack去裝數字與字串, 遇到 '[' 確認目前字串 ']'就pop
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  string decodeString(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ']')
      {
        st.push(s[i]);
      }
      else {
        string current_s = "";
        while (st.top() != '[')
        {
          current_s = st.top() + current_s;
          st.pop();
        }
        // pop '['
        st.pop();
        string current_num_string = "";

        while (!st.empty() && isdigit(st.top()))
        {
          current_num_string = st.top() + current_num_string;
          st.pop();
        }
        int time = stoi(current_num_string);

        while (time > 0)
        {
          for (char ele : current_s) {
            st.push(ele);
          }
          time--;
        }
      }
    }
    string ans = "";
    while (!st.empty())
    {
      ans = st.top() + ans ;
      st.pop();
    }
    return ans;
  }
};