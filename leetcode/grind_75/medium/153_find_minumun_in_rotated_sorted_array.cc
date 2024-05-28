// 時間複雜限定O(ln n), 用binary-search
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[start] < nums[end])
            {
                // 在最終排序的數列中, start是最小的而不是拿mid來用
                return nums[start];
            }

            if (nums[mid] >= nums[start])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        //  [2,1], [0] 如果用if硬寫會挺丑, 還是讓迴圈跑完讓start去決定最小值的起點
        return nums[start];
    }
};