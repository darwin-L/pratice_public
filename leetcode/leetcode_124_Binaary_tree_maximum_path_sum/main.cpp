
// Definition for a binary tree node.
#include<math.h>
#include <algorithm> 
#include <bits/stdc++.h>


// 不用排序, 只需要找最大的一條路徑並且包含最少一個點就可以

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        getMaxPathThroughNode(root);
        return maxPath;
    }private:
        int getMaxPathThroughNode(TreeNode* root)
        {
            if (root == NULL)
                return 0;
            int leftPath = getMaxPathThroughNode(root->left);
            int rightPath = getMaxPathThroughNode(root->right);

            int path1 = root->val;
            int path2 = root->val + max(leftPath, rightPath);
            int path3 = root->val + leftPath + rightPath;

            int curMaxPath = max(max(path1, path2), path3);

            if (curMaxPath > maxPath)
                maxPath = curMaxPath;

            return max(path1, path2);
        }

        int maxPath = INT_MIN;
};