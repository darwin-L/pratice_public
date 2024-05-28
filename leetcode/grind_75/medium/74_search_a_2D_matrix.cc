// 第一反應: 先直著找(columns) 再跟據離columns的遠近找橫的(row)
// 如果現實中有這種資料結構就好了, 直接降維打擊
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int columns = matrix[0].size() - 1;

        // level 直接等於 橫的總長會比較好寫, 但如果寫成彈性可以根據vertical判斷該從左邊逼近還是右邊逼近
        int vertical = 0;
        int level = columns;

        while (vertical < rows && level > -1)
        {
            int cur = matrix[vertical][level];
            if (cur == target)
                return true;
            if (target > cur)
            {
                vertical++;
            }
            else
            {
                level--;
            }
        }
        return false;
    }
};