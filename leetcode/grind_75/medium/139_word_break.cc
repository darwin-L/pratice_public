// 第一反應: 遍歷wordDict, 找該字串的start,end 截掉, 但這會有前面的元素就把string拆成無法組成的結果
// e.g. s= "cars". Dict = ["car","ca","rs"]
// e.g. s= "bb". Dict = ["a","b","bbb","bbbb"]
// 所以要用dp去紀錄走過的擷取路線
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // 轉成set查詢更快
    set<string> dict;
    for (auto w : wordDict)
      dict.insert(w);
    if (wordDict.size() == 0) return false;
    vector<bool> dp(s.size(), false);
    dp[0] = true;
    // 當陣列能夠被完整切割完成, dp[s.size()] 會是 true
    for (int i = 1;i <= s.size();i++)
    {
      for (int j = i - 1;j >= 0;j--)
      {
        if (dp[j])
        {
          string word = s.substr(j, i - j);
          if (dict.find(word) != dict.end())
          {
            dp[i] = true;
            break; //next i
          }
        }
      }
    }
    return dp[s.size()];
  }
};