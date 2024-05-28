// dp題, 類似 coin change, 但須列出所有步數
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        // 是以target下去以1做步長dp遍歷, 每次跑所有的數值
        for (int i = 1; i <= target; i++)
        {
            // for (auto num : nums)
            for (int j = 0; j < nums.size(); j++)
            {
                // 避開無解的解
                if (i < nums[j])
                    break;

                // 2147483647 magic number prevent overflow
                // [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]
                // 999
                dp[i] = (long(dp[i]) + dp[i - nums[j]]) % 2147483647;
            }
        }
        return dp.back();
    }
};

// 2147483647 預防overflow
