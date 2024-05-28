// 確認需要找的字串長度之後, 從s的0開始找字串長度,然後p要做成每個字母出現幾次的map(或是酷炫點用vector) 如果比不到就往下一個字元, 找到就往下p.length()個字元
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_of_s =  s.length();
        int len_of_p = p.length();

        if(s.size()< p.size()) return {};

        vector<int> char_record_of_p(26,0);
        vector<int> char_record_of_s(26,0);
        
        // init string compare;
        vector<int> ans;
        if(char_record_of_p == char_record_of_s) ans.push_back(0);

        for(int i = len_of_p; i <len_of_s; i ++) {
          // 去掉比較的頭
          char_record_of_s[s[i-len_of_p] - 'a']--;
          // 加上比較的尾
          char_record_of_s[s[i] - 'a']++;

          if(char_record_of_s == char_record_of_p) ans.push_back( i - len_of_p + 1);
        }
        return ans;
    }
};