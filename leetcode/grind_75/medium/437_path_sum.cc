// 第一反應: 相較於 113_path_sum_2 會有中段符合條件, 但因為不用處理路徑, 所以遞迴的每一次都拿新變數判斷
#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
    int ans = 0;

public:
    int pathSum(TreeNode *root, int target)
    {

        if (root)
        {
            // 不含root要個別跑
            dfs(root, target);
            // 子樹都要再次檢查root是否是能夠獨立成為一個路徑
            pathSum(root->left, target);
            pathSum(root->right, target);
        }
        return ans;
    }
    void dfs(TreeNode *root, long long sum)
    {
        if (root == nullptr)
            return;
        if (root->val == sum)
            this->ans++;

        sum -= root->val;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};