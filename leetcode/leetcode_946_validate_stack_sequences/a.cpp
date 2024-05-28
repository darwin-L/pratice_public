#include<vector>
#include<stack>
#include<iostream>

// 在一個長度趨近於無限大的push中, 能不能提前發現無解
class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> st;
        int i = 0;
        // 一邊推一邊看, 在push推完前要pop完
        for (int num : pushed) {
        	st.push(num);
        	while (!st.empty() && st.top() == popped[i]) {
        		st.pop();
        		++i;
            }
        }
        return st.empty();
    }
    // NOTE: not good for me
    bool validateStackSequences2(std::vector<int> &pushed, std::vector<int> &popped)
    {
        int i = 0, j = 0, k = 0, n = pushed.size();
        while (i < n)
        {
            pushed[k] = pushed[i];
            k++;
            while (j < n && k > 0 && pushed[k - 1] == popped[j])
            {
                j++;
                k--;
            }
            i++;
        }
        return j == n;
    }
};
int main(void){
    std::vector<int> a{1,2,3};
    std::vector<int> b{2,3,1};
    Solution* solution = new Solution();
    bool ans = solution->validateStackSequences(a,b);
    std::cout<<ans;
    std::cout<<"a";
}