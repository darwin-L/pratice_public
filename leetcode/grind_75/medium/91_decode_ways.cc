// 第一反應: dp題, 另一個問題點是 '0' 這個字元, 遇到0的時候往前抓一個(或往後)
// dp到最後取陣列最後一個元素(或最前)的值
#include <bits/stdc++.h>
using namespace std;
// NONE recursive, 比較直覺
class Solution {
public:
    int numDecodings(const string& s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') // Single digit
                dp[i] += dp[i+1];
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};

// 比較細節
class Solution
{
private:
public:
    int numDecodings(string s)
    {
        vector<int> memo(100, 0);
        dp(s,0,memo);
        return memo[0];
    }

    int dp(const string &s, int i, vector<int> &memo)
    {
        // 不看size-1因為要看倒數第二個的值決定是否回傳1
        if (i == s.size())
            return 1;
        
        // 拿前面計算過的結果來用
        if (memo[i] != 0)
            return memo[i];

        int ans = 0;
        if (s[i] != '0')
            ans += dp(s, i + 1, memo);

        if (i + 1 < s.size() &&
            (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
            ans += dp(s, i + 2, memo);
        
        memo[i] = ans;
        return memo[i];
    }
};