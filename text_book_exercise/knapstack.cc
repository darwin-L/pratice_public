// 一些回憶的連結: https://leetcode.com/discuss/study-guide/1152328/01-Knapsack-Problem-and-Dynamic-Programming
// 演算法筆記: https://web.ntnu.edu.tw/~algo/KnapsackProblem.html

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int> vec = {1, 7, 8, 5, 1, 3, 5, 7};
    int n = vec.size();
    // 假如最多取三個數
    vector<int> dp(3 + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // NOTE: 不能從0開始的原因: 整個陣列會只剩最大值
        //  for (int j = 0; j < 3; j++)
        //  {
        //      dp[j + 1] = max(dp[j + 1], dp[j] + vec[i]);
        //  }
        
        // j的變量來自dp的長度
        for (int j = 3; j > 0; j--)
        {
            dp[j] = max(dp[j], dp[j - 1] + vec[i]);
        }
    }

    for (auto ele : dp)
    {
        cout << ele << endl;
    }
    cout << dp.back();

    return 0;
}