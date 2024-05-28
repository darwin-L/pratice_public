// 第一反應: 奇數左到右, 偶數相反, 每一層調換順序
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        // 用兩個stack來互相代表目前層的值, 以及等等要被推入的子樹
        stack<TreeNode *> mainS;
        stack<TreeNode *> childS;
        mainS.push(root);
        int level = 1;
        vector<int> subAns;
        while (mainS.size() > 0)
        {
            TreeNode *front = mainS.top();
            mainS.pop(); 
            subAns.push_back(front->val);

            if (level % 2 == 1)
            { 
                if (front->left != NULL)
                {
                    childS.push(front->left);
                }
                if (front->right != NULL)
                {
                    childS.push(front->right);
                }
            }

            if (level % 2 == 0)
            {
                if (front->right != NULL)
                {
                    childS.push(front->right);
                }
                if (front->left != NULL)
                {
                    childS.push(front->left);
                }
            }

            if (mainS.size() == 0)
            {
                swap(childS, mainS);
                ans.push_back(subAns);
                subAns.clear();
                level++;
            }
        }
        return ans;
    }
};