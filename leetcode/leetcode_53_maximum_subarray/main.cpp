
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
class Solution
{
private:
    /* data */
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums);

        for (size_t i = 1; i < nums.size(); i++)
            dp[i] += dp[i - 1];

        int max;
        if (nums.size() > 0)
            max = nums[0];

        //循环所有的起点
        for (size_t i = 0; i < nums.size(); i++)
        {
            //循环所有可能的终点
            for (size_t j = i; j < nums.size(); j++)
            {
                int tmp = dp[j] - dp[i] + nums[i];
                if (tmp > max)
                    max = tmp;
            }
        }
        return max;
    }
    Solution(/* args */);
    ~Solution();
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(void)
{
    Solution sln;
    vector<int> test_case{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << sln.maxSubArray(test_case) << endl;
    return 0;
}
