// 第一反應: 在不用long前提下, 檢查overflow完事
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int r = 0;
        while (x)
        {
            // overflow前檢查前一步預期增長的範圍即可
            if (r > INT_MAX / 10 || r < INT_MIN / 10)
                return 0;
            r = r * 10 + x % 10; 
            x = x / 10;          
        }
        return r;
    }
};