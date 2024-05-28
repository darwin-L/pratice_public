// avl樹也可以被稱作 height balanced tree(高度平衡樹)
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 單一路線, 空間使用上會比較好
class Solution {
public:
  int depth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }

  bool is_balanced(TreeNode* root) {
    if (root == NULL) return true;
    // 有個corner-case要考慮: 以root為分界
    int left = depth(root->left);
    int right = depth(root->right);

    return (
      abs(left - right) &&
      is_balanced(root->right) &&
      is_balanced(root->left)
      );

  }
};

// 多路線, 理論上遍歷的次數比較少
class Solution2 {
public:
  int dfs(TreeNode* root) {
    if (root == NULL) return 0;

    int left_height = dfs(root->left);
    if (left_height == -1) return -1;

    int right_height = dfs(root->right);
    if (right_height == -1) return -1;

    if(abs(left_height - right_height) > 1) return -1;
    return max(left_height, right_height) + 1;
  }

  bool is_balanced(TreeNode* root) {
    int res = dfs(root);
    if (res != -1) {
      return true;
    }
    else {
      return false;
    }
  }
};