#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        std::vector<int> prefix(n, 1);
        std::vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            cout <<i<<":"<< prefix[i]<<" ";
        }
        cout<<endl;
        // 長度-1因為0, 再減1因為錯位
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
            cout <<i<<":"<< suffix[i]<<" ";
        }

        std::vector<int> answer(n);
        for (int i = 0; i < n; ++i)
        {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};
