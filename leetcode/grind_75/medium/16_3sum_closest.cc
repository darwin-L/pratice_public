// 第一反應: 背包問題, 但目標價值可以超過取最接近目標價值的
// 這種sum類型不能直接轉化成背包問題主要是在"一定要取N個"的這件事情在一般的貪心策略比較難達到(可行但繞)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        
        sort(nums.begin(), nums.end());
        
        int ans = nums[0] + nums[1] + nums[2];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int right = i + 1;
            int left = nums.size() - 1;
            while (right < left)
            {
                sum = nums[i] + nums[right] + nums[left];
                if (abs(target - ans) > abs(target - sum))
                {
                    ans = sum;
                    if (ans == target)
                        return ans;
                }
                (sum > target) ? left-- : right++;
            }
        }
        return ans;
    }
};