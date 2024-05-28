// 第一反應: sort陣列, 然後從 pow(10,9)裡面每一個10進位找最大的挑出來
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> ans;
        for (auto ele : nums)
        {
            ans.push_back(to_string(ele));
        }
        sort(
            ans.begin(),
            ans.end(),
            [](string &s1, string &s2)
            // 這行就是判斷長度
            { return s1 + s2 > s2 + s1; }); 
        string output;
        for(auto ele: ans) output+=ele;

        // 去除為0的input [0,0] -> 0
        while (output[0] == '0' && output.length() > 1)
        {
            output.erase(0,1);
        }
        
        return output;
    }
};