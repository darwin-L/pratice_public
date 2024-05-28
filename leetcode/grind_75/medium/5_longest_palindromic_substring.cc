// 從原始的字串開始, 設定左右兩個idx, 左移右移後檢查是否回文
// 回文檢查: 長度雙數切一半, 長度單數去掉中間那個 然後檢查兩邊是否相等
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 因為從左右會有被切斷的問題, 從中間開始往外推比較合理
    string longestPalindrome(string s)
    {

        if (s.size() <= 1)
            return s;

        int left_boundary = 0;
        int right_boundary = s.size() - 1;

        int global_max = 1; // 最少保證1字元的回文
        int ans_string_start_idx = 0;

        for (int i = 0; i < s.size();)
        {
            int left = i;
            int right = i;

            
            while (right < right_boundary && s[right] == s[right + 1])
            {
                right++;
            }
            i = right + 1;
            // 這個迭代與上面的while有相關連, 往一個方向的檢查才需要直接更改i
            // e.g. bananas

            // 得先檢查相鄰的, 再檢查互相交錯的
            while (right < right_boundary && left > 0 && s[left - 1] == s[right + 1])
            {
                right++;
                left--;
            }
            

            int current_max = right - left + 1;
            if (current_max > global_max)
            {
                ans_string_start_idx = left;
                global_max = current_max;
            }
        }
        return s.substr(ans_string_start_idx, global_max);
    }
};