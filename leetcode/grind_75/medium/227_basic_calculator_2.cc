// 第一反應: 一個stack就好, 用後序遍歷的方式處理
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    stack<int> post_order_stack;

public:
    int calculate(string s)
    {
        int ans = 0;
        int temp = 0;
        // integers will in range[0, pow(2,31) - 1], 這個條件讓一開始的sign直接指定成正數
        char sign = '+';
        for (int i = 0; i < s.length(); i++)
        {

            if (isdigit(s[i]))
                temp = temp * 10 + s[i] - '0';
            
            // 最後一個條件是要清空post_order_stack
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.length() - 1 )
            {                
                if (sign == '-')
                    post_order_stack.push(-temp);
                else if (sign == '+')
                    post_order_stack.push(temp);
                else
                {
                    int num;
                    if (sign == '*')
                        num = post_order_stack.top() * temp;
                    else
                        num = post_order_stack.top() / temp;
                    post_order_stack.pop();
                    post_order_stack.push(num);
                }
                sign = s[i];
                temp = 0;
            }
        }
        while (!post_order_stack.empty())
        {
            ans += post_order_stack.top();
            post_order_stack.pop();
        }
        return ans;
    }
};