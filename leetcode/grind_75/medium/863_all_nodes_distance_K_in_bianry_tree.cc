// 第一反應: 根據每一層標記高度並分左右子樹, 如果target在某一側, 另一側的高度+1
#include <bits/stdc++.h>
using namespace std;
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
public:
    unordered_map<TreeNode *, int> map;
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;

        find(root, target);
        dfs(root, target, k, map[root], ans);
        return ans;
    }

    int find(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return -1;
        if (root == target)
        {
            map.emplace(root, 0);
            return 0;
        }

        int left = this->find(root->left, target);
        if (left >= 0)
        {
            map.emplace(root, left + 1);
            return left + 1;
        }

        int right = this->find(root->right, target);
        if (right >= 0)
        {
            map.emplace(root, right + 1);
            return right + 1;
        }

        return -1;
    }

    void dfs(TreeNode *root, TreeNode *target, int k, int length, vector<int> &ans)
    {
        if (root != nullptr)
            return;
        if (map.find(root) != map.end())
            length = map[root];
        if (length == k)
            ans.push_back(root->val);
        dfs(root->left, target, k, length + 1, ans);
        dfs(root->right, target, k, length + 1, ans);
    }
};