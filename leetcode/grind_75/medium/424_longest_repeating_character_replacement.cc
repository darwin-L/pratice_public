// 第一反應: 利用K去跳過字元, 當遇到同個字元的時候算最大長度. 複雜度O((1 + n) * n / 2)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int characterReplacement(string s, int k) {
    int max_frequence = 0;
    int unconnectable_count = 0;
    vector<int> tabu(26);
    for (int i = 0; i < s.length(); ++i) {
      // 抓最常出現的字元, 類似最小子數列
      tabu[s[i] - 'A'] ++;
      max_frequence = max(max_frequence, tabu[s[i] - 'A']);

      
      if (i - unconnectable_count + 1 > max_frequence + k) {
        // 把預期字串的位置字元減去, 代表這個字串的價值減少了(用到了一個替代字元)
        tabu[s[unconnectable_count] - 'A']--;
        //unconnectable_count 代表前後容許k個替換字元卻依然無法連接的字串們
        unconnectable_count++;
      }
    }
    // cout << unconnectable_count << max_frequence;
    return  s.length() - unconnectable_count;
  }
};