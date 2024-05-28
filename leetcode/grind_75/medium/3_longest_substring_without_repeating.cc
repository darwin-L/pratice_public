// 第一反應: 儲存目前所抓到最長無重複字串, 用一個unordered_map去確認目前的無重複狀態, 遇到重複的重置map
#include<bits/stdc++.h>
using namespace std;
// pwwkew output為 wke 而非 kew 這個會影響迴圈的寫法
// TODO: 寫個用unorder_map 和 sub_string的易讀版本
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    // 256根據題目限制給個足夠大的unique vector size即可
    vector<int> vec_like_map(256, -1);
    // -1因為單一個字串長度的話是 1
    int max_len = 0, start = -1;
    // 如果使用map的話會需要額外儲存一個sub_string來確認目前的無重複字串長度, 所以使用vector直接用位置判斷可以省去sub_string的空間
    // 每一次的遍歷都會去檢查目前的字串夠不夠長, 但交換跟max的開銷都很小所以可以接受
    for (int i = 0; i < s.length(); i++) {
      if(vec_like_map[i] > start) start = vec_like_map[i];
      vec_like_map[s[i]] = i;
      max_len = max(max_len, i - start);
    }
    return max_len;
  }
};